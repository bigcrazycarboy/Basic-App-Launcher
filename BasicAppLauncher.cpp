// bigcrazycarboy
// 9.1.2026

#include <windows.h>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR lpCmdLine, int)
{
    if (!lpCmdLine || !*lpCmdLine)
    {
        MessageBoxA(
            nullptr,
            "Usage:\nLauncher.exe \"C:\\path\\to\\program.exe\"",
            "Launcher",
            MB_OK | MB_ICONERROR
        );
        return 1;
    }

    HINSTANCE result = ShellExecuteA(
        nullptr,
        "open",
        lpCmdLine,
        nullptr,
        nullptr,
        SW_SHOWNORMAL
    );

    if ((INT_PTR)result <= 32)
    {
        MessageBoxA(
            nullptr,
            "Failed to launch the executable.",
            "Launcher",
            MB_OK | MB_ICONERROR
        );
        return 1;
    }

    return 0;
}