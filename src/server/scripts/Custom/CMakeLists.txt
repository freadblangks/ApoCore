# Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# file(GLOB_RECURSE sources_Custom Custom/*.cpp Custom/*.h)

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
#  ${sources_Custom}
    Custom/Transmogrification.h
    Custom/Transmogrification.cpp
    Custom/Transmogrifier.cpp
    Custom/duel_reset.cpp
    Custom/GOMove.cpp
    Custom/PVPTitles.cpp
    Custom/toppvpnpc.cpp
    Custom/arena_spectator.cpp
    Custom/playertools.cpp
    Custom/lvl_rewards.cpp
    Custom/beastmaster.cpp
    Custom/top5kill.cpp
    Custom/killstreak.cpp
    Custom/chat.cpp
    Custom/npc_morpher.cpp
    Custom/npc_vip_vendor.cpp
)

message("  -> Prepared: Custom")
