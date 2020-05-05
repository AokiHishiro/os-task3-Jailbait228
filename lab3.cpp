#include "lab3.h"
#include <windows.h>
#include <stdio.h>
#define MAX_SEM_COUNT 10
#define THREADCOUNT 12
HANDLE ghSemaphoreA, ghSemaphoreB, ghSemaphoreD, ghSemaphoreG, ghSemaphoreK, ghSemaphoreM, ghSemaphoreH,ghSemaphoreI;
HANDLE aThread[THREADCOUNT];
DWORD WINAPI ThreadProc_c(LPVOID);
DWORD WINAPI ThreadProc_a(LPVOID);
DWORD WINAPI ThreadProc_b(LPVOID);
DWORD WINAPI ThreadProc_d(LPVOID);
DWORD WINAPI ThreadProc_f(LPVOID);
DWORD WINAPI ThreadProc_e(LPVOID);
DWORD WINAPI ThreadProc_g(LPVOID);
DWORD WINAPI ThreadProc_h(LPVOID);
DWORD WINAPI ThreadProc_k(LPVOID);
DWORD WINAPI ThreadProc_m(LPVOID);
DWORD WINAPI ThreadProc_i(LPVOID);
DWORD WINAPI ThreadProc_n(LPVOID);
unsigned int lab3_thread_graph_id()
{
    return 13;
}

const char* lab3_unsynchronized_threads()
{
    return "cdef";
}

const char* lab3_sequential_threads()
{
    return "ihm";
}
DWORD WINAPI ThreadProc_a(LPVOID)
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << "a";
    }
    return TRUE;
}
DWORD WINAPI ThreadProc_b(LPVOID)
{
    for (int i = 0; i < 3; i++)
    {
            WaitForSingleObject(ghSemaphoreA, INFINITE);
            std::cout << "b";
                computation();
                if (!ReleaseSemaphore(ghSemaphoreB,  1,  NULL))      
                {
                    printf("ReleaseSemaphore error: %d\n", GetLastError());
                }
    }
    return TRUE;
}
DWORD WINAPI ThreadProc_c(LPVOID)
{
    for (int i = 0; i < 3; i++)
    {
             WaitForSingleObject(ghSemaphoreB, INFINITE);
             std::cout << "c";
                computation();
                if (!ReleaseSemaphore(ghSemaphoreA,1, NULL)) 
                    printf("ReleaseSemaphore error: %d\n", GetLastError());
    }
    
    WaitForSingleObject(aThread[1], INFINITE);
    for (int i = 0; i < 3; i++)
    {
        std::cout << "c";
        computation();
    }
    return TRUE;
    
}
DWORD WINAPI ThreadProc_d(LPVOID)
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << "d";
        computation();
    }
    WaitForSingleObject(aThread[2], INFINITE);
    WaitForSingleObject(aThread[4], INFINITE);
    WaitForSingleObject(aThread[5], INFINITE);
   for (int i = 0; i < 3; i++)
    {
        WaitForSingleObject(ghSemaphoreD, INFINITE);
        std::cout << "d";
        computation();
        if (!ReleaseSemaphore(ghSemaphoreG, 1, NULL))
            printf("ReleaseSemaphore error: %d\n", GetLastError());
    }
    return TRUE;

}
DWORD WINAPI ThreadProc_e(LPVOID)
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << "e";
        computation();
    }
    return TRUE;

}
DWORD WINAPI ThreadProc_f(LPVOID)
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << "f";
        computation();
    }
    return TRUE;

}
DWORD WINAPI ThreadProc_g(LPVOID)
{
    for (int i = 0; i < 3; i++)
    {
        WaitForSingleObject(ghSemaphoreG, INFINITE);
        std::cout << "g";
        computation();
        if (!ReleaseSemaphore(ghSemaphoreH, 1, NULL))
            printf("ReleaseSemaphore error: %d\n", GetLastError());
    }
    return TRUE;
}
DWORD WINAPI ThreadProc_h(LPVOID)
{
    for (int i = 0; i < 3; i++)
    {
        WaitForSingleObject(ghSemaphoreH, INFINITE);
        std::cout << "h";
        computation();
        if (!ReleaseSemaphore(ghSemaphoreM, 1, NULL))
            printf("ReleaseSemaphore error: %d\n", GetLastError());
    }
    for (int i = 0; i < 3; i++)
    {
        WaitForSingleObject(ghSemaphoreH, INFINITE);
        std::cout << "h";
        computation();
        if (!ReleaseSemaphore(ghSemaphoreM, 1, NULL))
            printf("ReleaseSemaphore error: %d\n", GetLastError());
    }
    return TRUE;
}
DWORD WINAPI ThreadProc_m(LPVOID)
{
    for (int i = 0; i < 3; i++)
    {
        WaitForSingleObject(ghSemaphoreM, INFINITE);
        std::cout << "m";
        computation();
        if (!ReleaseSemaphore(ghSemaphoreK, 1, NULL))
            printf("ReleaseSemaphore error: %d\n", GetLastError());
    }
    for (int i = 0; i < 3; i++)
    {
        WaitForSingleObject(ghSemaphoreM, INFINITE);
        std::cout << "m";
        computation();
        if (!ReleaseSemaphore(ghSemaphoreI, 1, NULL))
            printf("ReleaseSemaphore error: %d\n", GetLastError());
    }
    return TRUE;
}
DWORD WINAPI ThreadProc_k(LPVOID)
{
    for (int i = 0; i < 3; i++)
    {
        WaitForSingleObject(ghSemaphoreK, INFINITE);
        std::cout << "k";
        computation();
        if (!ReleaseSemaphore(ghSemaphoreD, 1, NULL))
            printf("ReleaseSemaphore error: %d\n", GetLastError());
    }
    return TRUE;
}
DWORD WINAPI ThreadProc_i(LPVOID)
{
    for (int i = 0; i < 3; i++)
    {
        WaitForSingleObject(ghSemaphoreI, INFINITE);
        std::cout << "i";
        computation();
        if (!ReleaseSemaphore(ghSemaphoreH, 1, NULL))
            printf("ReleaseSemaphore error: %d\n", GetLastError());
    }
    return TRUE;
}
DWORD WINAPI ThreadProc_n(LPVOID)
{
    for (int i = 0; i < 3; i++)
    {
        std::cout<<"n";
        computation();
    }
    return TRUE;
}
int lab3_init()
{
    DWORD ThreadID;
    ghSemaphoreA = CreateSemaphore(NULL,0,1,NULL);
    if (ghSemaphoreA == NULL)
    {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }
    ghSemaphoreB = CreateSemaphore(NULL, 1, 1, NULL);
    if (ghSemaphoreB == NULL)
    {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }
    ghSemaphoreD = CreateSemaphore(NULL, 1, 1, NULL);
    if (ghSemaphoreD == NULL)
    {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }
    ghSemaphoreG = CreateSemaphore(NULL,0, 1, NULL);
    if (ghSemaphoreG == NULL)
    {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }
    ghSemaphoreK = CreateSemaphore(NULL, 0, 1, NULL);
    if (ghSemaphoreK == NULL)
    {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }
    ghSemaphoreM = CreateSemaphore(NULL, 0, 1, NULL);
    if (ghSemaphoreM == NULL)
    {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }
    ghSemaphoreH = CreateSemaphore(NULL, 0, 1, NULL);
    if (ghSemaphoreH == NULL)
    {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }
    ghSemaphoreI = CreateSemaphore(NULL, 1, 1, NULL);
    if (ghSemaphoreI == NULL)
    {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }
    aThread[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProc_a, NULL, 0, &ThreadID);
    if (aThread[0] == NULL)
    {
        printf("CreateThread error: %d\n", GetLastError());
        return 1;
    }
    WaitForMultipleObjects(1, aThread, TRUE, INFINITE);
    aThread[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProc_b, NULL, 0, &ThreadID);

        if (aThread[1] == NULL)
        {
            printf("CreateThread error: %d\n", GetLastError());
            return 1;
        }
        aThread[2] = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ThreadProc_c,NULL,0, &ThreadID);
        if (aThread[2] == NULL)
        {
            printf("CreateThread error: %d\n", GetLastError());
            return 1;
        }
        WaitForMultipleObjects(2, aThread, TRUE, INFINITE);
        aThread[3] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProc_d, NULL, 0, &ThreadID);
        if (aThread[3] == NULL)
        {
            printf("CreateThread error: %d\n", GetLastError());
            return 1;
        }
        aThread[4] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProc_e, NULL, 0, &ThreadID);
        if (aThread[4] == NULL)
        {
            printf("CreateThread error: %d\n", GetLastError());
            return 1;
        }
        aThread[5] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProc_f, NULL, 0, &ThreadID);
        if (aThread[5] == NULL)
        {
            printf("CreateThread error: %d\n", GetLastError());
            return 1;
        }
        WaitForMultipleObjects(3, aThread, TRUE, INFINITE);
        WaitForSingleObject(aThread[4], INFINITE);
        WaitForSingleObject(aThread[5], INFINITE);
        WaitForSingleObject(aThread[2], INFINITE);
        aThread[9] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProc_m, NULL, 0, &ThreadID);
        if (aThread[9] == NULL)
        {
            printf("CreateThread error: %d\n", GetLastError());
            return 1;
        }
        aThread[8] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProc_k, NULL, 0, &ThreadID);
        if (aThread[8] == NULL)
        {
            printf("CreateThread error: %d\n", GetLastError());
            return 1;
        }
        aThread[6] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProc_g, NULL, 0, &ThreadID);
        if (aThread[6] == NULL)
        {
            printf("CreateThread error: %d\n", GetLastError());
            return 1;
        }
        aThread[7] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProc_h, NULL, 0, &ThreadID);
        if (aThread[7] == NULL)
        {
            printf("CreateThread error: %d\n", GetLastError());
            return 1;
        }
        WaitForSingleObject(aThread[3], INFINITE);
        WaitForSingleObject(aThread[6], INFINITE);
        WaitForSingleObject(aThread[8], INFINITE);
        aThread[10] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProc_i, NULL, 0, &ThreadID);
        if (aThread[10] == NULL)
        {
            printf("CreateThread error: %d\n", GetLastError());
            return 1;
        }
        WaitForSingleObject(aThread[10], INFINITE);
        WaitForSingleObject(aThread[7], INFINITE);
        WaitForSingleObject(aThread[9], INFINITE);
        aThread[11] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProc_n, NULL, 0, &ThreadID);
        if (aThread[11] == NULL)
        {
            printf("CreateThread error: %d\n", GetLastError());
            return 1;
        }
       
        WaitForSingleObject(aThread[11], INFINITE);
        WaitForMultipleObjects(12, aThread, TRUE, INFINITE);
        for (int i = 0; i < THREADCOUNT; i++)
            CloseHandle(aThread[i]);
    CloseHandle(ghSemaphoreA);
    CloseHandle(ghSemaphoreB);
    CloseHandle(ghSemaphoreD);
    CloseHandle(ghSemaphoreG);
    CloseHandle(ghSemaphoreH);
    CloseHandle(ghSemaphoreK);
    CloseHandle(ghSemaphoreM);
    CloseHandle(ghSemaphoreI);
    return 0;
}
