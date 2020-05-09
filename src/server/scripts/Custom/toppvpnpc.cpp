
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Player.h"
#include <cstring>

class npc_pvpladder : public CreatureScript
{
public:
    npc_pvpladder() : CreatureScript("npc_pvpladder") { }

    std::string classtostring(uint16 class_id)
    {
        const char* classStr = NULL;
        switch (class_id)
        {
          //warrior
        case CLASS_WARRIOR: classStr = "|TInterface\\ICONS\\inv_sword_27:20:20:0:0|t";
            break;
          //paladin
        case CLASS_PALADIN: classStr = "|TInterface\\ICONS\\ability_thunderbolt:20:20:0:0|t";
            break;
          //hunter
        case CLASS_HUNTER: classStr = "|TInterface\\ICONS\\inv_weapon_bow_07:20:20:0:0|t";
            break;
          //rogue
        case CLASS_ROGUE: classStr = "|TInterface\\ICONS\\inv_throwingknife_04:20:20:0:0|t";
            break;
          //priest
        case CLASS_PRIEST: classStr = "|TInterface\\ICONS\\inv_staff_30:20:20:0:0|t";
            break;
          //Deathknight
        case CLASS_DEATH_KNIGHT: classStr = "|TInterface\\ICONS\\spell_deathknight_classicon:20:20:0:0|t";
            break;
          //Shaman
        case CLASS_SHAMAN: classStr = "|TInterface\\ICONS\\spell_nature_bloodlust:20:20:0:0|t";
            break;
          //mage
        case CLASS_MAGE: classStr = "|TInterface\\ICONS\\inv_staff_13.jpg:20:20:0:0|t";
            break;
          //Warlock
        case CLASS_WARLOCK: classStr = "|TInterface\\ICONS\\spell_nature_drowsy:20:20:0:0|t";
            break;
          //Druid
        case CLASS_DRUID: classStr = "|TInterface\\ICONS\\Ability_Druid_Maul:20:20:0:0|t";
            break;
        default: classStr = "|TInterface\\ICONS\\Inv_misc_questionmark:20:20:0:0|t";
            break;
        }
        return classStr;
    }

    std::string killstorank(uint8 race, uint32 kills)
    {
        const char* rankStr = NULL;
        // alliance icons [blue]
        if ((race == RACE_HUMAN) || (race == RACE_DWARF) || (race == RACE_NIGHTELF) || (race == RACE_GNOME) || (race == RACE_DRAENEI))
        {
            if (kills < 250) // rank under 250 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_A_01:20:20:0:0|t";
            else if (kills >= 250 && kills < 500) // rank at 250 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_A_02:20:20:0:0|t";
            else if (kills >= 500 && kills < 750) // rank at 500 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_A_03:20:20:0:0|t";
            else if (kills >= 750 && kills < 1000) // rank at 750 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_A_04:20:20:0:0|t";
            else if (kills >= 1000 && kills < 1250) // rank at 1000 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_A_05:20:20:0:0|t";
            else if (kills >= 1250 && kills < 1500) // rank at 1250 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_A_06:20:20:0:0|t";
            else if (kills >= 1500 && kills < 1750) // rank at 1500 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_A_07:20:20:0:0|t";
            else if (kills >= 1750 && kills < 2000) // rank at 1750 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_A_08:20:20:0:0|t";
            else if (kills >= 2000 && kills < 2250) // rank at 2000 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_A_09:20:20:0:0|t";
            else if (kills >= 2250 && kills < 2500) // rank at 2250 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_A_10:20:20:0:0|t";
            else if (kills >= 2500 && kills < 2750) // rank at 2500 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_A_11:20:20:0:0|t";
            else if (kills >= 2750 && kills < 3000) // rank at 2750 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_A_12:20:20:0:0|t";
            else if (kills >= 3000 && kills < 4000) // rank at 3000 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_A_13:20:20:0:0|t";
            else if (kills >= 4000 && kills < 7000) // rank at 4000 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_A_14:20:20:0:0|t";
            else if (kills >= 7000 && kills < 10000) // rank at 7000 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_A_15:20:20:0:0|t";
            else if (kills >= 10000) // rank at 10000+ kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_P_250K:20:20:0:0|t";
            else
                rankStr = "|TInterface\\ICONS\\Inv_misc_questionmark:20:20:0:0|t";
        }
        else // horde icons [red]
        {
            if (kills < 250) // rank under 250 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_H_01:20:20:0:0|t";
            else if (kills >= 250 && kills < 500) // rank at 250 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_H_02:20:20:0:0|t";
            else if (kills >= 500 && kills < 750) // rank at 500 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_H_03:20:20:0:0|t";
            else if (kills >= 750 && kills < 1000) // rank at 750 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_H_04:20:20:0:0|t";
            else if (kills >= 1000 && kills < 1250) // rank at 1000 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_H_05:20:20:0:0|t";
            else if (kills >= 1250 && kills < 1500) // rank at 1250 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_H_06:20:20:0:0|t";
            else if (kills >= 1500 && kills < 1750) // rank at 1500 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_H_07:20:20:0:0|t";
            else if (kills >= 1750 && kills < 2000) // rank at 1750 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_H_08:20:20:0:0|t";
            else if (kills >= 2000 && kills < 2250) // rank at 2000 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_H_09:20:20:0:0|t";
            else if (kills >= 2250 && kills < 2500) // rank at 2250 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_H_10:20:20:0:0|t";
            else if (kills >= 2500 && kills < 2750) // rank at 2500 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_H_11:20:20:0:0|t";
            else if (kills >= 2750 && kills < 3000) // rank at 2750 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_H_12:20:20:0:0|t";
            else if (kills >= 3000 && kills < 4000) // rank at 3000 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_H_13:20:20:0:0|t";
            else if (kills >= 4000 && kills < 7000) // rank at 4000 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_H_14:20:20:0:0|t";
            else if (kills >= 7000 && kills < 10000) // rank at 7000 kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_H_15:20:20:0:0|t";
            else if (kills >= 10000) // rank at 10000+ kills
                rankStr = "|TInterface\\ICONS\\Achievement_PVP_P_250K:20:20:0:0|t";
            else
                rankStr = "|TInterface\\ICONS\\Inv_misc_questionmark:20:20:0:0|t";
        }
        return rankStr;
    }

    std::string ratingtorank(uint32 rating, uint8 type)
    {
        const char* rankStr = NULL;
        if (type == 2)
        {
            if (rating < 1700) // if rating under 1700
                rankStr = "|TInterface\\ICONS\\Achievement_Arena_2v2_3:20:20:0:0|t";
            else if (rating >= 1700 && rating < 1900) // if rating at 1700+
                rankStr = "|TInterface\\ICONS\\Achievement_Arena_2v2_5:20:20:0:0|t";
            else if (rating >= 1900 && rating < 2100) // if rating at 1900+
                rankStr = "|TInterface\\ICONS\\Achievement_Arena_2v2_7:20:20:0:0|t";
            else if (rating >= 2100) // if rating at 2100+
                rankStr = "|TInterface\\ICONS\\Achievement_FeatsOfStrength_Gladiator_02:20:20:0:0|t";
            else
                rankStr = "|TInterface\\ICONS\\Inv_misc_questionmark:20:20:0:0|t";
        }
        if (type == 3)
        {
            if (rating < 1700) // if rating under 1700
                rankStr = "|TInterface\\ICONS\\Achievement_Arena_3v3_1:20:20:0:0|t";
            else if (rating >= 1700 && rating < 1900) // if rating at 1700+
                rankStr = "|TInterface\\ICONS\\Achievement_Arena_3v3_6:20:20:0:0|t";
            else if (rating >= 1900 && rating < 2100) // if rating at 1900+
                rankStr = "|TInterface\\ICONS\\Achievement_Arena_3v3_7:20:20:0:0|t";
            else if (rating >= 2100) // if rating at 2100+
                rankStr = "|TInterface\\ICONS\\Achievement_FeatsOfStrength_Gladiator_09:20:20:0:0|t";
            else
                rankStr = "|TInterface\\ICONS\\Inv_misc_questionmark:20:20:0:0|t";
        }
        if (type == 5)
        {
            if (rating < 1700) // if rating under 1700
                rankStr = "|TInterface\\ICONS\\Achievement_Arena_5v5_1:20:20:0:0|t";
            else if (rating >= 1700 && rating < 1900) // if rating at 1700+
                rankStr = "|TInterface\\ICONS\\Achievement_Arena_5v5_5:20:20:0:0|t";
            else if (rating >= 1900 && rating < 2100) // if rating at 1900+
                rankStr = "|TInterface\\ICONS\\Achievement_Arena_5v5_7:20:20:0:0|t";
            else if (rating >= 2100) // if rating at 2100+
                rankStr = "|TInterface\\ICONS\\Achievement_FeatsOfStrength_Gladiator_04:20:20:0:0|t";
            else
                rankStr = "|TInterface\\ICONS\\Inv_misc_questionmark:20:20:0:0|t";
        }
        return rankStr;
    }

    bool ShowArenaTeams(Player* player, Creature* creature, uint16 arena)
    {
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "|TInterface\\PaperDollInfoFrame\\UI-GearManager-Undo:24:24:0:0|t |cff6E353A RETURN|r", GOSSIP_SENDER_MAIN, 0);
	    
        QueryResult result = CharacterDatabase.PQuery("SELECT `name`, `rating` FROM `arena_team` WHERE `type`=%u ORDER BY `rating` DESC LIMIT 5", arena);
        if(!result)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface\\ICONS\\Inv_misc_questionmark:24:24:0:0|t |cffFF0000No Results!|r", GOSSIP_SENDER_MAIN, 0);
            player->PlayerTalkClass->SendGossipMenu(68, creature->GetGUID());
            return false;
        }
	    
        switch(arena)
        {
        case 2:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface\\ICONS\\Achievement_Leader_King_Varian_Wrynn:24:24:0:0|t|cff434343 PvP Ladder 2v2 arena!|r", GOSSIP_SENDER_MAIN, 0);
        break;
        case 3:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface\\ICONS\\Achievement_Leader_King_Varian_Wrynn:24:24:0:0|t|cff434343 PvP Ladder 3v3 arena!|r", GOSSIP_SENDER_MAIN, 0);
        break;
        case 5:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface\\ICONS\\Achievement_Leader_King_Varian_Wrynn:24:24:0:0|t|cff434343 PvP Ladder 5v5 arena!|r", GOSSIP_SENDER_MAIN, 0);
        break;
        }

        uint16 counter = 0;
        Field * fields = NULL;
        do
        {
            std::ostringstream result_string;
	    
            fields = result->Fetch();
            std::string team_name = fields[0].GetString();
            uint32 team_rating = fields[1].GetUInt32();
	    
            counter += 1;
            result_string << ratingtorank(team_rating, arena) << " " << counter << " - TEAM |cffFF0000[" << team_name.c_str() <<"]|r\nRating:|cffAB00FF " << team_rating << "|r";
	    
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, result_string.str().c_str(), GOSSIP_SENDER_MAIN, 0);
        
        }while(result->NextRow());
        player->PlayerTalkClass->SendGossipMenu(68, creature->GetGUID());
        return true;
    }

	bool OnGossipHello(Player* player, Creature* creature) override
    {
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "|TInterface\\ICONS\\Achievement_FeatsOfStrength_Gladiator_02:24:24:0:0|t |cffFF0000[PvP]|r Top 9 Killers", GOSSIP_SENDER_MAIN, 1);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "|TInterface\\ICONS\\Achievement_FeatsOfStrength_Gladiator_02:24:24:0:0|t |cffFF0000[PvP]|r Top 5 Arena 2v2", GOSSIP_SENDER_MAIN, 2);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "|TInterface\\ICONS\\Achievement_FeatsOfStrength_Gladiator_09:24:24:0:0|t |cffFF0000[PvP]|r Top 5 Arena 3v3", GOSSIP_SENDER_MAIN, 3);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "|TInterface\\ICONS\\Achievement_FeatsOfStrength_Gladiator_04:24:24:0:0|t |cffFF0000[PvP]|r Top 5 Arena 5v5", GOSSIP_SENDER_MAIN, 4);

        player->PlayerTalkClass->SendGossipMenu(68, creature->GetGUID());
        return true;
    }
    
	bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();
        switch(action)
        {
        case 0: // main menu
            OnGossipHello(player, creature);
            break;
        case 1: // top x killers
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "|TInterface\\PaperDollInfoFrame\\UI-GearManager-Undo:24:24:0:0|t |cff6E353A RETURN|r", GOSSIP_SENDER_MAIN, 0);

            QueryResult result = CharacterDatabase.Query("SELECT `name`, `race`, `class`, `totalKills` FROM `characters` WHERE `totalKills`>=1 ORDER BY `totalKills` DESC LIMIT 9");
            if(!result)
            {
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface\\ICONS\\Inv_misc_questionmark:24:24:0:0|t |cffFF0000No Results!|r", GOSSIP_SENDER_MAIN, 0);
                player->PlayerTalkClass->SendGossipMenu(68, creature->GetGUID());
                return false;
            }

            uint16 counter = 0;
            Field * fields = NULL;
            do
            {
                std::ostringstream result_string;

                fields = result->Fetch();
                std::string char_name = fields[0].GetString();
                uint16 char_race = fields[1].GetUInt16();
                uint16 char_class = fields[2].GetUInt16();
                uint32 char_kills = fields[3].GetUInt32();
		    
                counter += 1;
                result_string << killstorank(char_race, char_kills) << " " << counter << " " << classtostring(char_class) << " Name |cffFF0000[" << char_name.c_str() <<"]|r, Kills:|cffAB00FF " << char_kills << "|r";
		    
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, result_string.str().c_str(), GOSSIP_SENDER_MAIN, 0);
            
            }while(result->NextRow());
            player->PlayerTalkClass->SendGossipMenu(68, creature->GetGUID());
        } break;
        case 2: // top x 2v2 arenas
            ShowArenaTeams(player, creature, 2);
        break;
        case 3: // top x 3v3 arenas
            ShowArenaTeams(player, creature, 3);
        break;
        case 4: // top x 5v5 arenas
            ShowArenaTeams(player, creature, 5);
        break;
        }
    
        return true;
    }
};

void AddSC_npc_pvpladder()
{
    new npc_pvpladder();
}


            //case GOSSIP_ACTION_INFO_DEF+1:
            //{
            //    //QueryResult result = CharacterDatabase.PQuery("SELECT `session_id` FROM `board_lottery_game` WHERE `session_status`='1'");
            //    //return result ? result->Fetch()[0].GetUInt32() : 0;
            //    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "|TInterface\\PaperDollInfoFrame\\UI-GearManager-Undo:24:24:0:0|t |cff6E353A RETURN|r", GOSSIP_SENDER_MAIN, 0);
		    
            //    QueryResult result = CharacterDatabase.Query("SELECT `name`, `class`, `totalKills` FROM `characters` WHERE `totalKills` > 0 ORDER BY totalKills DESC LIMIT 10");
            //    if(!result)
            //    {
            //        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|cffFF0000there is no result|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+0);
            //        return false;
            //    }
		    
            //    uint8 counter = 0;
            //    std::ostringstream result_string;
		    
            //    Field * fields = NULL;
            //    do
            //    {
            //        fields = result->Fetch();
            //        std::string char_name     = fields[0].GetString();
            //        uint8 char_class          = fields[1].GetUInt8();
            //        uint32 char_kills         = fields[2].GetUInt32();

            //        result_string << ". Name: " << char_name.c_str() << "; Class: " << char_class << "; Kills:" << char_kills << ";";
		    
            //        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, result_string.str().c_str(), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+0);
            //    
            //    }while(result->NextRow());
            //    player->PlayerTalkClass->SendGossipMenu(68, creature->GetGUID());
            //}
