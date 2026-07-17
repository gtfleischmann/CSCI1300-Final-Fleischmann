Remove-Item .\krobus.exe -ErrorAction SilentlyContinue
g++ -std=c++11 -Wall -Wextra mainfinal.cpp char.cpp char_player.cpp char_npc.cpp loc.cpp item.cpp game.cpp -o krobus.exe
if ($LASTEXITCODE -eq 0) {
    .\krobus.exe
}
