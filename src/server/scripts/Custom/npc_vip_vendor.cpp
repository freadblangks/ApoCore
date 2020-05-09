/* Copyright (C) 2012 for TrinityCore <http://trinity-core.ru/>
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/ // creature_template: npc_vip_vendor //

#include "ScriptPCH.h"

class npc_vip_vendor : public CreatureScript
{
public:
    npc_vip_vendor() : CreatureScript("npc_vip_vendor") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (player->GetSession()->IsPremium())
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);
            player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        }
		else
		{
			player->CLOSE_GOSSIP_MENU();
			creature->MonsterWhisper("Niestety nie posiadasz konta/postaci VIP.", player, false);
		}
		return true;

    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 uiSender, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();

        if (uiAction == GOSSIP_ACTION_TRADE)
            player->GetSession()->SendListInventory(creature->GetGUID());
        return true;
    }
};

void AddSC_npc_vip_vendor()
{
    new npc_vip_vendor;
}