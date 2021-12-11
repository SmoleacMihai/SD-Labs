#include <iostream>
#include <ctype.h>
#include <string.h>
#include <string>
#include <conio.h>

typedef char string[20];
int m, n, i, j, k, t;
char x, y;
string a[10][10], b[10][10], c[10][10], p, l;
int main()
{
    std::cout << "Numarul de varfuri: ";
    std::cin >> n;
    std::cout << "Numarul de arce: ";
    std::cin >> m;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            strcpy(a[i][j], "0");
    for (i = 1; i <= m; i++)
    {
        std::cout << "Extremitatile arc " << i << " ";
        std::cin >> x >> y;
        x = toupper(x);
        y = toupper(y);
        char *z;
        switch (y)
        {
        case 'A':
            z = "A";
            break;
        case 'B':
            z = "B";
            break;
        case 'C':
            z = "C";
            break;
        case 'D':
            z = "D";
            break;
        case 'E':
            z = "E";
            break;
        case 'F':
            z = "F";
            break;
        case 'G':
            z = "G";
            break;
        case 'H':
            z = "H";
            break;
        case 'I':
            z = "I";
            break;
        case 'J':
            z = "J";
            break;
        }
        strcpy(a[(int)x - 64][(int)y - 64], z);
    }
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            strcpy(b[i][j], a[i][j]);
    for (t = 2; t <= n - 1; t++)
    {
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
            {
                strcpy(c[i][j], "0");
                for (k = 1; k <= n; k++)
                {
                    int i1, j1, e = 0;
                    for (i1 = 0; i1 < strlen(a[i][k]); i1++)
                        for (j1 = 0; j1 < strlen(b[k][j]); j1++)
                            if (a[i][k][i1] == b[k][j][j1])
                                e = 1;
                    if ((strcmp(a[i][k], "0") == 0) ||
                        (strcmp(b[k][j], "0") == 0) || (e == 1))
                        strcpy(l, "0");
                    else
                    {
                        strcpy(l, "");
                        strcpy(l, a[i][k]);
                        strcat(l, b[k][j]);
                    }
                    if (strrchr(l, (char)(i + 64)))
                        strcpy(l, "0");
                    if (strcmp(l, "0") != 0)
                    {
                        if (strcmp(c[i][j], "0") == 0)
                            strcpy(c[i][j], "");
                        if (strcmp(c[i][j], "") != 0)
                            strcat(c[i][j], ",");
                        strcat(c[i][j], l);
                    }
                }
            }
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                strcpy(b[i][j], c[i][j]);
    }
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            strcpy(c[i][j], "0");
            for (k = 1; k <= n; k++)
            {
                int i1, j1, e = 0;
                for (i1 = 0; i1 < strlen(a[i][k]); i1++)
                    for (j1 = 0; j1 < strlen(b[k][j]); j1++)
                        if (a[i][k][i1] == b[k][j][j1])
                            e = 1;
                if ((strcmp(a[i][k], "0") == 0) ||
                    (strcmp(b[k][j], "0") == 0) || (e == 1))
                    strcpy(l, "0");
                else
                {
                    strcpy(l, "");
                    strcpy(l, a[i][k]);
                    strcat(l, b[k][j]);
                }
                if (strcmp(l, "0") != 0)
                {
                    if (strcmp(c[i][j], "0") == 0)
                        strcpy(c[i][j], "");
                    if (strcmp(c[i][j], "") != 0)
                        strcat(c[i][j], ",");
                    strcat(c[i][j], l);
                }
            }
        }
    for (i = 1; i <= n; i++)
    {
        if (strcmp(c[i][i], "0") != 0)
        {
            switch (i)
            {
            case 1:
                std::cout << 'A';
                break;
            case 2:
                std::cout << 'B';
                break;
            case 3:
                std::cout << 'C';
                break;
            case 4:
                std::cout << 'D';
                break;
            case 5:
                std::cout << 'E';
                break;
            case 6:
                std::cout << 'F';
                break;
            case 7:
                std::cout << 'G';
                break;
            case 8:
                std::cout << 'H';
                break;
            case 9:
                std::cout << 'I';
                break;
            case 10:
                std::cout << 'J';
                break;
            }
            std::cout << c[i][i] << std::endl;
        }
    }
    getch();
    return 0;
}