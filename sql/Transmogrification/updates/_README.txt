Supported TC version
https://github.com/TrinityCore/TrinityCore/commit/0d8ba1233e89c3d7e87dc98ca89be38e9688576b

Clean installation:
1. Download Transmogrification.diff and place it to your source folder
2. Apply the diff with git apply Transmogrification.diff
3. Use Cmake
4. (Re)compile
5. Navigate to \sql\Transmogrification
6. Run characters.sql to your characters database
7. Run world_texts.sql to your world database
8. Change the settings to your liking in worldserver.conf (Note that you should copy over the new config created)

9. optionally you can also insert a transmogrifier NPC to your database by running world_NPC.sql to your world database.

Already have an old version?
Updating from 5.4 to 5.5:
Use git apply -R Transmogrification.diff to remove the old code and download the new version and install the diff normally.
