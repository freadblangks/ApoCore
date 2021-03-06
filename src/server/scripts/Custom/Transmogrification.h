//alfa 01.07.2014
#ifndef DEF_TRANSMOGRIFICATION_H
#define DEF_TRANSMOGRIFICATION_H

#define PRESETS // comment this line to disable preset feature totally
#define MAX_OPTIONS 25 // do not alter

class Item;
class Player;
class WorldSession;
struct ItemTemplate;

enum TransmogTrinityStrings // Language.h might have same entries, appears when executing SQL, change if needed
{
    LANG_ERR_TRANSMOG_OK = 11100, // change this
    LANG_ERR_TRANSMOG_INVALID_SLOT,
    LANG_ERR_TRANSMOG_INVALID_SRC_ENTRY,
    LANG_ERR_TRANSMOG_MISSING_SRC_ITEM,
    LANG_ERR_TRANSMOG_MISSING_DEST_ITEM,
    LANG_ERR_TRANSMOG_INVALID_ITEMS,
    LANG_ERR_TRANSMOG_NOT_ENOUGH_MONEY,
    LANG_ERR_TRANSMOG_NOT_ENOUGH_TOKENS,

    LANG_ERR_UNTRANSMOG_OK,
    LANG_ERR_UNTRANSMOG_NO_TRANSMOGS,

#ifdef PRESETS
    LANG_PRESET_ERR_INVALID_NAME,
#endif
};

class Transmogrification
{
public:
    template <typename K, typename V>
    class KVRWHashMap
    {
    public:
        typedef std::unordered_map<K, V> MapType;
        typedef ACE_RW_Thread_Mutex LockType;

        void Insert(K k, V v)
        {
            TRINITY_WRITE_GUARD(LockType, i_lock);
            m_hashMap[k] = v;
        }

        void Remove(K k)
        {
            TRINITY_WRITE_GUARD(LockType, i_lock);
            m_hashMap.erase(k);
        }

        // Note, returns a pointer to a copy of the value
        // You MUST manually delete it to avoid mem leaks
        // use ACE_Auto_Ptr<K>
        V* GetCopy(K k)
        {
            TRINITY_READ_GUARD(LockType, i_lock);
            typename MapType::iterator itr = m_hashMap.find(k);
            if (itr != m_hashMap.end())
                return new V(itr->second);
            else
                return NULL;
        }

        MapType& GetContainer() { return m_hashMap; }

        LockType& GetLock() { return i_lock; }

    private:

        LockType i_lock;
        MapType m_hashMap;
    };

#ifdef PRESETS
    typedef std::map<uint8, uint32> presetslotMap;
    struct presetData
    {
        std::string name;
        presetslotMap slotMap;
    };
    typedef std::map<uint8, presetData> presetIdMap; // remember to lock
    typedef KVRWHashMap<uint64, presetIdMap> presetPlayers;
    presetPlayers presetMap; // presetByName[pGUID][presetID] = presetData

    bool EnableSetInfo;
    uint32 SetNpcText;

    bool EnableSets;
    uint8 MaxSets;
    float SetCostModifier;
    int32 SetCopperCost;

    void LoadPlayerSets(uint64 pGUID);
    void UnloadPlayerSets(uint64 pGUID);

    void PresetTransmog(Player* player, Item* itemTransmogrified, uint32 fakeEntry, uint8 slot);
#endif

    typedef std::unordered_map<uint64, uint32> transmogData; // remember to lock
    typedef KVRWHashMap<uint64, transmogData> transmogMap;
    // typedef KVRWHashMap<uint64, uint64> transmogPlayers;
    transmogMap entryMap; // entryMap[pGUID][iGUID] = entry
    // transmogPlayers playerMap; // dataMap[iGUID] = pGUID

    bool EnableTransmogInfo;
    uint32 TransmogNpcText;

    // Use IsAllowed() and IsNotAllowed()
    // these are thread unsafe, but assumed to be static data so it should be safe
    std::set<uint32> Allowed;
    std::set<uint32> NotAllowed;

    float ScaledCostModifier;
    int32 CopperCost;

    bool RequireToken;
    uint32 TokenEntry;
    uint32 TokenAmount;

    bool AllowPoor;
    bool AllowCommon;
    bool AllowUncommon;
    bool AllowRare;
    bool AllowEpic;
    bool AllowLegendary;
    bool AllowArtifact;
    bool AllowHeirloom;

    bool AllowMixedArmorTypes;
    bool AllowMixedWeaponTypes;
    bool AllowFishingPoles;

    bool IgnoreReqRace;
    bool IgnoreReqClass;
    bool IgnoreReqSkill;
    bool IgnoreReqSpell;
    bool IgnoreReqLevel;
    bool IgnoreReqEvent;
    bool IgnoreReqStats;

    bool IsAllowed(uint32 entry) const;
    bool IsNotAllowed(uint32 entry) const;
    bool IsAllowedQuality(uint32 quality) const;
    bool IsRangedWeapon(uint32 Class, uint32 SubClass) const;

    void LoadConfig(bool reload); // thread unsafe

    std::string GetItemIcon(uint32 entry, uint32 width, uint32 height, int x, int y) const;
    std::string GetSlotIcon(uint8 slot, uint32 width, uint32 height, int x, int y) const;
    const char * GetSlotName(uint8 slot, WorldSession* session) const;
    std::string GetItemLink(Item* item, WorldSession* session) const;
    std::string GetItemLink(uint32 entry, WorldSession* session) const;
    uint32 GetFakeEntry(const Item* item);
    void UpdateItem(Player* player, Item* item) const;
    void DeleteFakeEntry(Player* player, Item* item);
    void SetFakeEntry(Player* player, Item* item, uint32 entry);

    TransmogTrinityStrings Transmogrify(Player* player, uint64 itemGUID, uint8 slot, bool no_cost = false);
    bool CanTransmogrifyItemWithItem(Player* player, ItemTemplate const* destination, ItemTemplate const* source) const;
    bool SuitableForTransmogrification(Player* player, ItemTemplate const* proto) const;
    // bool CanBeTransmogrified(Item const* item);
    // bool CanTransmogrify(Item const* item);
    uint32 GetSpecialPrice(ItemTemplate const* proto) const;
    std::vector<uint64> GetItemList(const Player* player) const;
};
#define sTransmogrification ACE_Singleton<Transmogrification, ACE_Null_Mutex>::instance()

#endif