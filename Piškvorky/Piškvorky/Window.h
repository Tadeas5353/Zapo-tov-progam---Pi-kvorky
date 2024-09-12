#include <commctrl.h>
#include <cstdlib>
#include "Board.h"
#include "Const.h"
#include "TechWindow.h"

HWND hwndButtonFriend;
HWND hwndButtonBot;
HWND hwndButtonZacit;
HWND hwndButtonPotvrdittahKriz;
HWND hwndButtonPotvrdittahKruh;
HWND hwndButtonRestart;
HWND hwndButtonKonec;
HWND hwndTrackbarHeigth;
HWND hwndTrackbarWidth;
HWND hwndTrackbarCon;
HWND hwndTrackbarBot;
HWND hwndTrackbarStart;
HWND hwndLabelHeigth;
HWND hwndLabelWidth;
HWND hwndLabelCon;
HWND hwndLabelBot;
HWND hwndLabelStart;
HWND hwndLabelPismeno;
HWND hwndLabelCislo;
HWND hwndLabelVitez;
HWND hwndTrackbarPismeno;
HWND hwndTrackbarCislo;
HWND hwndPolicko;
HWND hwndWidth;
HWND hwndHeigth;
HWND hwndcon;
HWND hwndbot;
HWND hwndstart;
int souper;
bool nakreslit = false;
int starter;
int nejnovejsiX;
int nejnovejsiY;
int counter;
hraci_plocha Hraci_plocha;

class Window {
public:
    static HWND hwnd;

    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
        
        int Cislo;
        char Pismeno;
        policko position;
        bool nekdo_vyhral;

        switch (uMsg) {

        case WM_CREATE: {
            Window::hwnd = hwnd;

            RECT rect;
            GetClientRect(hwnd, &rect);

            int centerX = (rect.right - BUTTON_WIDTH) / 2;
            int centerY = (rect.bottom - BUTTON_HEIGHT) / 2;

            hwndButtonFriend = CreateWindow(
                L"BUTTON",  
                L"Hrát s kamarádem",    
                WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  
                centerX,    
                centerY - 40,  
                BUTTON_WIDTH,  
                BUTTON_HEIGHT,  
                hwnd,  
                (HMENU)1,  
                (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
                nullptr);

            hwndButtonBot = CreateWindow(
                L"BUTTON",  
                L"Hrát s poèítaèem",  
                WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  
                centerX,    
                centerY + 10,  
                BUTTON_WIDTH,  
                BUTTON_HEIGHT,  
                hwnd,  
                (HMENU)2,  
                (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
                nullptr);

            return 0;
        }

        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            switch (wmId) {
            case 1:
            {
                ShowWindow(hwndButtonFriend, SW_HIDE);
                ShowWindow(hwndButtonBot, SW_HIDE);
                vyber_hrace();
                souper = 0;
                break;
            }
            case 2:
            {
                ShowWindow(hwndButtonFriend, SW_HIDE);
                ShowWindow(hwndButtonBot, SW_HIDE);
                vyber_hrace();

                souper = 1;

                int centerX;
                int centerY;

                RECT rect;
                GetClientRect(Window::hwnd, &rect);

                centerX = (rect.right - TRACKBAR_WIDTH) / 2;
                centerY = (rect.bottom - TRACKBAR_HEIGHT) / 2;

                hwndTrackbarBot = CreateWindowEx(
                    0, TRACKBAR_CLASS, NULL,
                    WS_CHILD | WS_VISIBLE | TBS_HORZ,
                    centerX, centerY + 2 * TRACKBAR_HEIGHT + 2*LABEL_HEIGHT, TRACKBAR_WIDTH, TRACKBAR_HEIGHT,
                    Window::hwnd, NULL, (HINSTANCE)GetWindowLongPtr(Window::hwnd, GWLP_HINSTANCE), NULL);

                SendMessage(hwndTrackbarBot, TBM_SETRANGE, TRUE, MAKELPARAM(TRACKBAR_MIN_Alt, TRACKBAR_MIN));
                SendMessage(hwndTrackbarBot, TBM_SETPOS, TRUE, TRACKBAR_MIN_Alt);

                hwndLabelBot = CreateWindowEx(
                    0, L"STATIC", L"Úroveò bota",
                    WS_CHILD | WS_VISIBLE | SS_CENTER,
                    centerX, centerY + 2*TRACKBAR_HEIGHT + LABEL_HEIGHT, TRACKBAR_WIDTH, LABEL_HEIGHT,
                    Window::hwnd, NULL, (HINSTANCE)GetWindowLongPtr(Window::hwnd, GWLP_HINSTANCE), NULL);

                hwndTrackbarStart = CreateWindowEx(
                    0, TRACKBAR_CLASS, NULL,
                    WS_CHILD | WS_VISIBLE | TBS_HORZ,
                    centerX, centerY - 2 * TRACKBAR_HEIGHT - 2 * LABEL_HEIGHT, TRACKBAR_WIDTH, TRACKBAR_HEIGHT,
                    Window::hwnd, NULL, (HINSTANCE)GetWindowLongPtr(Window::hwnd, GWLP_HINSTANCE), NULL);

                SendMessage(hwndTrackbarStart, TBM_SETRANGE, TRUE, MAKELPARAM(TRACKBAR_MIN_Alt, TRACKBAR_MAX_P));
                SendMessage(hwndTrackbarStart, TBM_SETPOS, TRUE, TRACKBAR_MIN_Alt);

                hwndLabelStart = CreateWindowEx(
                    0, L"STATIC", L"Kdo bude zaèínat?",
                    WS_CHILD | WS_VISIBLE | SS_CENTER,
                    centerX, centerY - 3 * TRACKBAR_HEIGHT - LABEL_HEIGHT, TRACKBAR_WIDTH, LABEL_HEIGHT,
                    Window::hwnd, NULL, (HINSTANCE)GetWindowLongPtr(Window::hwnd, GWLP_HINSTANCE), NULL);

                hwndbot = CreateWindow(
                    L"STATIC",
                    L"Opilec",
                    WS_CHILD | WS_VISIBLE | SS_CENTER,
                    (rect.right - TRACKBAR_HEIGHT + LABEL_HEIGHT) / 2 + TRACKBAR_WIDTH / 2 + 12,
                    centerY + 2 * TRACKBAR_HEIGHT + LABEL_HEIGHT,
                    2 * (TRACKBAR_HEIGHT + LABEL_HEIGHT),
                    TRACKBAR_HEIGHT + LABEL_HEIGHT,
                    Window::hwnd,
                    nullptr,
                    (HINSTANCE)GetWindowLongPtr(Window::hwnd, GWLP_HINSTANCE),
                    nullptr);

                hwndstart = CreateWindow(
                    L"STATIC",
                    L"Hráè",
                    WS_CHILD | WS_VISIBLE | SS_CENTER,
                    (rect.right - TRACKBAR_HEIGHT + LABEL_HEIGHT) / 2 + TRACKBAR_WIDTH / 2 + 12,
                    centerY - 2 * TRACKBAR_HEIGHT - 3 * LABEL_HEIGHT,
                    2 * (TRACKBAR_HEIGHT + LABEL_HEIGHT),
                    TRACKBAR_HEIGHT + LABEL_HEIGHT,
                    Window::hwnd,
                    nullptr,
                    (HINSTANCE)GetWindowLongPtr(Window::hwnd, GWLP_HINSTANCE),
                    nullptr);

                LOGFONT lf = {};
                lf.lfHeight = 20;
                lstrcpy(lf.lfFaceName, L"Times new roman");
                HFONT hFont = CreateFontIndirect(&lf);

                SendMessage(hwndbot, WM_SETFONT, (WPARAM)hFont, TRUE);
                SendMessage(hwndstart, WM_SETFONT, (WPARAM)hFont, TRUE);

                break;
            }

            case 3:
            {
                int sirska = SendMessage(hwndTrackbarWidth, TBM_GETPOS, 0, 0);
                int vyska = SendMessage(hwndTrackbarHeigth, TBM_GETPOS, 0, 0);
                int vyherni_cislo = SendMessage(hwndTrackbarCon, TBM_GETPOS, 0, 0);

                counter = 0;

                if (mensi(sirska, vyska) < vyherni_cislo)
                {
                    MessageBox(hwnd, L"Poèet políèek nutný k výhøe se musí vejít do hracího plánu.", L"Chyba", MB_OK);
                }

                else
                {
                    if (souper != 0)
                    {
                        souper = SendMessage(hwndTrackbarBot, TBM_GETPOS, 0, 0);
                        starter = SendMessage(hwndTrackbarStart, TBM_GETPOS, 0, 0);
                    }

                    else
                    {
                        starter = 1;
                    }

                    Hraci_plocha.heigth = vyska;
                    Hraci_plocha.width = sirska;
                    Hraci_plocha.k_vyhre = vyherni_cislo;
                    Hraci_plocha.natahu = 1;
                    Hraci_plocha.vitez = 0;
                    Hraci_plocha.dohrano = FALSE;
                    Hraci_plocha.Souper = souper;
                    Hraci_plocha.zaloz();
                    counter = 0;
                    
                    DestroyWindow(hwndButtonRestart);
                    DestroyWindow(hwndButtonKonec);
                    DestroyWindow(hwndLabelVitez);

                    ShowWindow(hwndTrackbarWidth, SW_HIDE);
                    ShowWindow(hwndTrackbarHeigth, SW_HIDE);
                    ShowWindow(hwndTrackbarCon, SW_HIDE);
                    ShowWindow(hwndcon, SW_HIDE);
                    ShowWindow(hwndWidth, SW_HIDE);
                    ShowWindow(hwndHeigth, SW_HIDE);
                    ShowWindow(hwndButtonZacit, SW_HIDE);
                    ShowWindow(hwndLabelWidth, SW_HIDE);
                    ShowWindow(hwndLabelHeigth, SW_HIDE);
                    ShowWindow(hwndLabelCon, SW_HIDE);

                    if (souper != 0)
                    {
                        ShowWindow(hwndTrackbarBot, SW_HIDE);
                        ShowWindow(hwndTrackbarStart, SW_HIDE);
                        ShowWindow(hwndLabelBot, SW_HIDE);
                        ShowWindow(hwndLabelStart, SW_HIDE);
                        ShowWindow(hwndstart, SW_HIDE);
                        ShowWindow(hwndbot, SW_HIDE);
                    }

                    nakreslit = true;
                    InvalidateRect(hwnd, nullptr, TRUE);

                    hraje_krouzek();
                }
                break;
            }

            case 4:
            {
                int Y = SendMessage(hwndTrackbarCislo, TBM_GETPOS, 0, 0) - 1;
                int X = SendMessage(hwndTrackbarPismeno, TBM_GETPOS, 0, 0) - 1;

                if (Hraci_plocha.plocha[Y][X] != 46)
                {
                    MessageBox(hwnd, L"Toto políèko je již obsazené", L"Chyba", MB_OK);
                }

                else
                {
                    DestroyWindow(hwndLabelPismeno);
                    DestroyWindow(hwndLabelCislo);
                    DestroyWindow(hwndTrackbarPismeno);
                    DestroyWindow(hwndTrackbarCislo);
                    DestroyWindow(hwndPolicko);
                    DestroyWindow(hwndButtonPotvrdittahKriz);
                    DestroyWindow(hwndButtonPotvrdittahKruh);

                    Hraci_plocha.plocha[Y][X] = 79;
                    nejnovejsiX = X;
                    nejnovejsiY = Y;

                    nakreslit = true;
                    InvalidateRect(hwnd, nullptr, TRUE);

                    bool nekdo_vyhral = zkontroluj_vyhru(Hraci_plocha.plocha, X, Y, Hraci_plocha.k_vyhre, Hraci_plocha.width, Hraci_plocha.heigth);

                    if (nekdo_vyhral)
                    {
                        Hraci_plocha.nekdo_vyhral();
                    }
                    if (counter == Hraci_plocha.width * Hraci_plocha.heigth)
                    {
                        Hraci_plocha.dohrano = true;
                    }
                    if (Hraci_plocha.dohrano)
                    {
                        dohrano();
                    }
                    else
                    {
                        hraje_krizek();
                    }
                }

                break;
            }

            case 5:
            {
                int Y = SendMessage(hwndTrackbarCislo, TBM_GETPOS, 0, 0) - 1;
                int X = SendMessage(hwndTrackbarPismeno, TBM_GETPOS, 0, 0) - 1;

                if (Hraci_plocha.plocha[Y][X] != 46)
                {
                    MessageBox(hwnd, L"Toto políèko je již obsazené", L"Chyba", MB_OK);
                }

                else
                {
                    DestroyWindow(hwndLabelPismeno);
                    DestroyWindow(hwndLabelCislo);
                    DestroyWindow(hwndTrackbarPismeno);
                    DestroyWindow(hwndTrackbarCislo);
                    DestroyWindow(hwndPolicko);
                    DestroyWindow(hwndButtonPotvrdittahKriz);
                    DestroyWindow(hwndButtonPotvrdittahKruh);

                    Hraci_plocha.plocha[Y][X] = 120;
                    nejnovejsiX = X;
                    nejnovejsiY = Y;

                    nakreslit = true;
                    InvalidateRect(hwnd, nullptr, TRUE);

                    bool nekdo_vyhral = zkontroluj_vyhru(Hraci_plocha.plocha, X, Y, Hraci_plocha.k_vyhre, Hraci_plocha.width, Hraci_plocha.heigth);

                    if (nekdo_vyhral)
                    {
                        Hraci_plocha.nekdo_vyhral();
                    }
                    if (counter == Hraci_plocha.width * Hraci_plocha.heigth)
                    {
                        Hraci_plocha.dohrano = true;
                    }
                    if (Hraci_plocha.dohrano)
                    {
                        dohrano();
                    }
                    else
                    {
                        hraje_krouzek();
                    }
                }
                break;
            }

            case 6:
            {
                exit(0);
            }

            default:
                return DefWindowProc(hwnd, uMsg, wParam, lParam);
            }
            return 0;
        }

        case WM_HSCROLL: {
            if ((HWND)lParam == hwndTrackbarWidth) {
                int value = SendMessage(hwndTrackbarWidth, TBM_GETPOS, 0, 0);
                std::wstring valueText = std::to_wstring(value);
                SetWindowText(hwndWidth, valueText.c_str());
            }

            if ((HWND)lParam == hwndTrackbarHeigth) {
                int value = SendMessage(hwndTrackbarHeigth, TBM_GETPOS, 0, 0);
                std::wstring valueText = std::to_wstring(value);
                SetWindowText(hwndHeigth, valueText.c_str());
            }

            if ((HWND)lParam == hwndTrackbarCon) {
                int value = SendMessage(hwndTrackbarCon, TBM_GETPOS, 0, 0);
                std::wstring valueText = std::to_wstring(value);
                SetWindowText(hwndcon, valueText.c_str());
            }
            
            if ((HWND)lParam == hwndTrackbarBot) {
                int value = SendMessage(hwndTrackbarBot, TBM_GETPOS, 0, 0);

                switch (value)
                {
                case 1:
                {
                    std::wstring valueText = L"Opilec";
                    SetWindowText(hwndbot, valueText.c_str());
                    break;
                }
                case 2:
                {
                    std::wstring valueText = L"Zaèáteèník";
                    SetWindowText(hwndbot, valueText.c_str());
                    break;
                }
                case 3:
                {
                    std::wstring valueText = L"Pokroèilý";
                    SetWindowText(hwndbot, valueText.c_str());
                    break;
                }
                }
                return 0;
            }

            if ((HWND)lParam == hwndTrackbarStart) {
                int value = SendMessage(hwndTrackbarStart, TBM_GETPOS, 0, 0);

                switch (value)
                {
                case 1:
                {
                    std::wstring valueText = L"Hráè";
                    SetWindowText(hwndstart, valueText.c_str());
                    break;
                }
                case 2:
                {
                    std::wstring valueText = L"Poèítaè";
                    SetWindowText(hwndstart, valueText.c_str());
                    break;
                }
                }
                return 0;
            }

            if ((HWND)lParam == hwndTrackbarCislo) {
                int number = SendMessage(hwndTrackbarCislo, TBM_GETPOS, 0, 0);
                char letter = abecedni_prevod(SendMessage(hwndTrackbarPismeno, TBM_GETPOS, 0, 0));

                std::string pozitionen = Tvorpolicko(letter, number);
                std::wstring wposition = stringToWstring(pozitionen);

                SetWindowText(hwndPolicko, wposition.c_str());
            }

            if ((HWND)lParam == hwndTrackbarPismeno) {
                int number = SendMessage(hwndTrackbarCislo, TBM_GETPOS, 0, 0);
                char letter = abecedni_prevod(SendMessage(hwndTrackbarPismeno, TBM_GETPOS, 0, 0));

                std::string pozitionen = Tvorpolicko(letter, number);
                std::wstring wposition = stringToWstring(pozitionen);

                SetWindowText(hwndPolicko, wposition.c_str());
            }
        }

        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            RECT rect;
            GetClientRect(hwnd, &rect);
            HBRUSH hBrushBackground = CreateSolidBrush(RGB(0, 0, 0));
            FillRect(hdc, &rect, hBrushBackground);
            DeleteObject(hBrushBackground);

            SetTextColor(hdc, RGB(255, 0, 0));
            SetBkMode(hdc, TRANSPARENT);

            LOGFONT lf = {};
            lf.lfHeight = 80;
            lstrcpy(lf.lfFaceName, L"Algerian");
            HFONT hFont = CreateFontIndirect(&lf);
            HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);

            const wchar_t* text = L"PIŠKVORKY";

            rect.top += 50;  
            DrawText(hdc, text, -1, &rect, DT_CENTER | DT_TOP | DT_SINGLELINE);

            SelectObject(hdc, hOldFont);
            DeleteObject(hFont);

            DrawTable(hdc, rect);

            EndPaint(hwnd, &ps);
            return 0;
        }

        case WM_SIZE: {
            RECT rect;
            GetClientRect(hwnd, &rect);

            int centerX = (rect.right - BUTTON_WIDTH) / 2;
            int centerY = (rect.bottom - BUTTON_HEIGHT) / 2;

            SetWindowPos(hwndButtonFriend, nullptr, centerX, centerY - 40, 0, 0, SWP_NOZORDER | SWP_NOSIZE);

            SetWindowPos(hwndButtonBot, nullptr, centerX, centerY + 10, 0, 0, SWP_NOZORDER | SWP_NOSIZE);

            if (hwndTrackbarHeigth) {
                SetWindowPos(hwndTrackbarHeigth, nullptr, centerX, centerY, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
                SetWindowPos(hwndLabelHeigth, nullptr, centerX, centerY - LABEL_HEIGHT, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
                SetWindowPos(hwndHeigth, nullptr, (rect.right - TRACKBAR_HEIGHT + LABEL_HEIGHT) / 2 + TRACKBAR_WIDTH / 2 + 12,
                    centerY - LABEL_HEIGHT, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
            }

            if (hwndTrackbarWidth) {
                SetWindowPos(hwndTrackbarWidth, nullptr, centerX, centerY - TRACKBAR_HEIGHT - LABEL_HEIGHT, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
                SetWindowPos(hwndLabelWidth, nullptr, centerX, centerY - 2* TRACKBAR_HEIGHT, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
                SetWindowPos(hwndWidth, nullptr, (rect.right - TRACKBAR_HEIGHT + LABEL_HEIGHT) / 2 + TRACKBAR_WIDTH / 2 + 12,
                    centerY - 2 * LABEL_HEIGHT - TRACKBAR_HEIGHT, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
            }

            if (hwndTrackbarCon) {
                SetWindowPos(hwndTrackbarCon, nullptr, centerX, centerY + TRACKBAR_HEIGHT + LABEL_HEIGHT, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
                SetWindowPos(hwndLabelCon, nullptr, centerX, centerY + TRACKBAR_HEIGHT, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
                SetWindowPos(hwndcon, nullptr, (rect.right - TRACKBAR_HEIGHT + LABEL_HEIGHT) / 2 + TRACKBAR_WIDTH / 2 + 12,
                    centerY + TRACKBAR_HEIGHT, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
            }

            if (hwndTrackbarBot)
            {
                SetWindowPos(hwndTrackbarBot, nullptr, centerX, centerY + 2*(TRACKBAR_HEIGHT + LABEL_HEIGHT), 0, 0, SWP_NOZORDER | SWP_NOSIZE);
                SetWindowPos(hwndLabelBot, nullptr, centerX, centerY + 2*TRACKBAR_HEIGHT + LABEL_HEIGHT, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
                SetWindowPos(hwndbot, nullptr, (rect.right - TRACKBAR_HEIGHT + LABEL_HEIGHT) / 2 + TRACKBAR_WIDTH / 2 + 12,
                    centerY + 2 * TRACKBAR_HEIGHT + LABEL_HEIGHT, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
            }

            if (hwndTrackbarStart)
            {
                SetWindowPos(hwndTrackbarStart, nullptr, centerX, centerY - 2 * (TRACKBAR_HEIGHT + LABEL_HEIGHT), 0, 0, SWP_NOZORDER | SWP_NOSIZE);
                SetWindowPos(hwndLabelStart, nullptr, centerX, centerY - 3 * TRACKBAR_HEIGHT - LABEL_HEIGHT, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
                SetWindowPos(hwndstart, nullptr, (rect.right - TRACKBAR_HEIGHT + LABEL_HEIGHT) / 2 + TRACKBAR_WIDTH / 2 + 12,
                    centerY - 2 * TRACKBAR_HEIGHT - 3 * LABEL_HEIGHT, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
            }
            
            if (hwndButtonZacit)
            {
                SetWindowPos(hwndButtonZacit, nullptr, centerX, centerY + 5 * TRACKBAR_HEIGHT, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
            }

            if (hwndTrackbarCislo)
            {
                SetWindowPos(hwndTrackbarCislo, nullptr, centerX - TRACKBAR_WIDTH / 2 - 20, 0.9 * rect.bottom, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
                SetWindowPos(hwndLabelCislo, nullptr, centerX - TRACKBAR_WIDTH / 2 - 20, 0.9 * rect.bottom - TRACKBAR_HEIGHT, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
                SetWindowPos(hwndTrackbarPismeno, nullptr, centerX + TRACKBAR_WIDTH / 2 + 20, 0.9 * rect.bottom, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
                SetWindowPos(hwndLabelPismeno, nullptr, centerX + TRACKBAR_WIDTH / 2 + 20, 0.9 * rect.bottom - TRACKBAR_HEIGHT, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
                SetWindowPos(hwndPolicko, nullptr, 0.8 * rect.right, 0.9 * rect.bottom - TRACKBAR_HEIGHT, 0, 0, SWP_NOZORDER | SWP_NOSIZE);

            }

            if (hwndButtonPotvrdittahKriz)
            {
                SetWindowPos(hwndButtonPotvrdittahKriz, nullptr, 0.05 * rect.right, 0.9 * rect.bottom - TRACKBAR_HEIGHT, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
            }

            if (hwndButtonPotvrdittahKruh)
            {
                SetWindowPos(hwndButtonPotvrdittahKruh, nullptr, 0.05 * rect.right, 0.9 * rect.bottom - TRACKBAR_HEIGHT, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
            }

            if (hwndLabelVitez) {
                SetWindowPos(hwndLabelVitez, nullptr, centerX, 0.9 * rect.bottom - TRACKBAR_HEIGHT, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
            }
            InvalidateRect(hwnd, nullptr, TRUE);

            if (hwndButtonRestart) {
                SetWindowPos(hwndButtonRestart, nullptr, 0.1 * rect.right, 0.9 * rect.bottom - TRACKBAR_HEIGHT, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
                SetWindowPos(hwndButtonKonec, nullptr, 0.9 * rect.right - BUTTON_WIDTH, 0.9 * rect.bottom - TRACKBAR_HEIGHT, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
            }

            return 0;
        }

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
        }
    }

    static void hraje_krouzek()
    {
        Hraci_plocha.natahu = 1;
        counter++;

        if (souper == 0 or starter == 1)
        {
            Window::hwnd = hwnd;

            RECT rect;
            GetClientRect(hwnd, &rect);

            int centerX = (rect.right - BUTTON_WIDTH) / 2;
            int centerY = (rect.bottom - BUTTON_HEIGHT) / 2;

            hwndTrackbarCislo = CreateWindowEx(
                0, TRACKBAR_CLASS, NULL,
                WS_CHILD | WS_VISIBLE | TBS_HORZ,
                centerX + TRACKBAR_WIDTH/2 + 20, 0.9*rect.bottom, TRACKBAR_WIDTH, TRACKBAR_HEIGHT,
                Window::hwnd, NULL, (HINSTANCE)GetWindowLongPtr(Window::hwnd, GWLP_HINSTANCE), NULL);

            SendMessage(hwndTrackbarCislo, TBM_SETRANGE, TRUE, MAKELPARAM(TRACKBAR_MIN_Alt, Hraci_plocha.heigth));
            SendMessage(hwndTrackbarCislo, TBM_SETPOS, TRUE, TRACKBAR_MIN_Alt);

            hwndTrackbarPismeno = CreateWindowEx(
                0, TRACKBAR_CLASS, NULL,
                WS_CHILD | WS_VISIBLE | TBS_HORZ,
                centerX - TRACKBAR_WIDTH / 2 - 20, 0.9 * rect.bottom, TRACKBAR_WIDTH, TRACKBAR_HEIGHT,
                Window::hwnd, NULL, (HINSTANCE)GetWindowLongPtr(Window::hwnd, GWLP_HINSTANCE), NULL);

            SendMessage(hwndTrackbarPismeno, TBM_SETRANGE, TRUE, MAKELPARAM(TRACKBAR_MIN_Alt, Hraci_plocha.width));
            SendMessage(hwndTrackbarPismeno, TBM_SETPOS, TRUE, TRACKBAR_MIN_Alt);

            hwndLabelCislo = CreateWindowEx(
                0, L"STATIC", L"Výbìr souøaadnice na ose Y",
                WS_CHILD | WS_VISIBLE | SS_CENTER,
                centerX + TRACKBAR_WIDTH / 2 + 20, 0.9 * rect.bottom - TRACKBAR_HEIGHT, TRACKBAR_WIDTH, LABEL_HEIGHT,
                Window::hwnd, NULL, (HINSTANCE)GetWindowLongPtr(Window::hwnd, GWLP_HINSTANCE), NULL);

            hwndLabelPismeno = CreateWindowEx(
                0, L"STATIC", L"Výbìr souøaadnice na ose X",
                WS_CHILD | WS_VISIBLE | SS_CENTER,
                centerX - TRACKBAR_WIDTH / 2 - 20, 0.9 * rect.bottom - TRACKBAR_HEIGHT, TRACKBAR_WIDTH, LABEL_HEIGHT,
                Window::hwnd, NULL, (HINSTANCE)GetWindowLongPtr(Window::hwnd, GWLP_HINSTANCE), NULL);

            hwndPolicko = CreateWindowEx(
                0, L"STATIC", L"A1",
                WS_CHILD | WS_VISIBLE | SS_CENTER,
                0.8 * rect.right, 0.9 * rect.bottom - TRACKBAR_HEIGHT, TRACKBAR_WIDTH/2.5, TRACKBAR_WIDTH / 4,
                Window::hwnd, NULL, (HINSTANCE)GetWindowLongPtr(Window::hwnd, GWLP_HINSTANCE), NULL);

            LOGFONT lf = {};
            lf.lfHeight = 70;
            lstrcpy(lf.lfFaceName, L"Bradley hand ITC");
            HFONT hFont = CreateFontIndirect(&lf);

            SendMessage(hwndPolicko, WM_SETFONT, (WPARAM)hFont, TRUE);

            hwndButtonPotvrdittahKruh = CreateWindow(
                L"BUTTON",
                L"Potvrdit políèko",
                WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                0.05*rect.right,
                0.9*rect.bottom - TRACKBAR_HEIGHT,
                BUTTON_WIDTH/2,
                BUTTON_HEIGHT,
                hwnd,
                (HMENU)4,
                (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
                nullptr);        
        }

        else
        {
            policko pole;

            pole = Hraci_plocha.tah_bota();

            int X = pole.souradnice_x - 65;
            int Y = pole.souradnice_y;

            Hraci_plocha.plocha[Y][X] = 79;
            nejnovejsiX = X;
            nejnovejsiY = Y;

            nakreslit = true;
            InvalidateRect(hwnd, nullptr, TRUE);

            bool nekdo_vyhral = zkontroluj_vyhru(Hraci_plocha.plocha, X, Y, Hraci_plocha.k_vyhre, Hraci_plocha.width, Hraci_plocha.heigth);

            if (nekdo_vyhral)
            {
                Hraci_plocha.nekdo_vyhral();
            }
            if (counter == Hraci_plocha.width * Hraci_plocha.heigth)
            {
                Hraci_plocha.dohrano = true;
            }
            if (Hraci_plocha.dohrano)
            {
                dohrano();
            }
            else
            {
                hraje_krizek();
            }
        }
    }

    static void hraje_krizek()
    {
        Hraci_plocha.natahu = 2;
        counter++;

        if (souper == 0 or starter == 2)
        {
            Window::hwnd = hwnd;

            RECT rect;
            GetClientRect(hwnd, &rect);

            int centerX = (rect.right - BUTTON_WIDTH) / 2;
            int centerY = (rect.bottom - BUTTON_HEIGHT) / 2;

            hwndTrackbarCislo = CreateWindowEx(
                0, TRACKBAR_CLASS, NULL,
                WS_CHILD | WS_VISIBLE | TBS_HORZ,
                centerX + TRACKBAR_WIDTH / 2 + 20, 0.9 * rect.bottom, TRACKBAR_WIDTH, TRACKBAR_HEIGHT,
                Window::hwnd, NULL, (HINSTANCE)GetWindowLongPtr(Window::hwnd, GWLP_HINSTANCE), NULL);

            SendMessage(hwndTrackbarCislo, TBM_SETRANGE, TRUE, MAKELPARAM(TRACKBAR_MIN_Alt, Hraci_plocha.heigth));
            SendMessage(hwndTrackbarCislo, TBM_SETPOS, TRUE, TRACKBAR_MIN_Alt);

            hwndTrackbarPismeno = CreateWindowEx(
                0, TRACKBAR_CLASS, NULL,
                WS_CHILD | WS_VISIBLE | TBS_HORZ,
                centerX - TRACKBAR_WIDTH / 2 - 20, 0.9 * rect.bottom, TRACKBAR_WIDTH, TRACKBAR_HEIGHT,
                Window::hwnd, NULL, (HINSTANCE)GetWindowLongPtr(Window::hwnd, GWLP_HINSTANCE), NULL);

            SendMessage(hwndTrackbarPismeno, TBM_SETRANGE, TRUE, MAKELPARAM(TRACKBAR_MIN_Alt, Hraci_plocha.width));
            SendMessage(hwndTrackbarPismeno, TBM_SETPOS, TRUE, TRACKBAR_MIN_Alt);

            hwndLabelCislo = CreateWindowEx(
                0, L"STATIC", L"Výbìr souøaadnice na ose Y",
                WS_CHILD | WS_VISIBLE | SS_CENTER,
                centerX + TRACKBAR_WIDTH / 2 + 20, 0.9 * rect.bottom - TRACKBAR_HEIGHT, TRACKBAR_WIDTH, LABEL_HEIGHT,
                Window::hwnd, NULL, (HINSTANCE)GetWindowLongPtr(Window::hwnd, GWLP_HINSTANCE), NULL);

            hwndLabelPismeno = CreateWindowEx(
                0, L"STATIC", L"Výbìr souøaadnice na ose X",
                WS_CHILD | WS_VISIBLE | SS_CENTER,
                centerX - TRACKBAR_WIDTH / 2 - 20, 0.9 * rect.bottom - TRACKBAR_HEIGHT, TRACKBAR_WIDTH, LABEL_HEIGHT,
                Window::hwnd, NULL, (HINSTANCE)GetWindowLongPtr(Window::hwnd, GWLP_HINSTANCE), NULL);

            hwndPolicko = CreateWindowEx(
                0, L"STATIC", L"A1",
                WS_CHILD | WS_VISIBLE | SS_CENTER,
                0.8 * rect.right, 0.9 * rect.bottom - TRACKBAR_HEIGHT, TRACKBAR_WIDTH / 2.5, TRACKBAR_WIDTH / 4,
                Window::hwnd, NULL, (HINSTANCE)GetWindowLongPtr(Window::hwnd, GWLP_HINSTANCE), NULL);

            LOGFONT lf = {};
            lf.lfHeight = 70;
            lstrcpy(lf.lfFaceName, L"Bradley hand ITC");
            HFONT hFont = CreateFontIndirect(&lf);

            SendMessage(hwndPolicko, WM_SETFONT, (WPARAM)hFont, TRUE);

            hwndButtonPotvrdittahKriz = CreateWindow(
                L"BUTTON",
                L"Potvrdit políèko",
                WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                0.05 * rect.right,
                0.9 * rect.bottom - TRACKBAR_HEIGHT,
                BUTTON_WIDTH / 2,
                BUTTON_HEIGHT,
                hwnd,
                (HMENU)5,
                (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
                nullptr);
        }

        else
        {
            policko pole;

            pole = Hraci_plocha.tah_bota();

            int X = pole.souradnice_x - 65;
            int Y = pole.souradnice_y;

            Hraci_plocha.plocha[Y][X] = 120;
            nejnovejsiX = X;
            nejnovejsiY = Y;

            nakreslit = true;
            InvalidateRect(hwnd, nullptr, TRUE);

            bool nekdo_vyhral = zkontroluj_vyhru(Hraci_plocha.plocha, X, Y, Hraci_plocha.k_vyhre, Hraci_plocha.width, Hraci_plocha.heigth);

            if (nekdo_vyhral)
            {
                Hraci_plocha.nekdo_vyhral();
            }
            if (counter == Hraci_plocha.width * Hraci_plocha.heigth)
            {
                Hraci_plocha.dohrano = true;
            }
            if (Hraci_plocha.dohrano)
            {
                dohrano();
            }
            else
            {
                hraje_krouzek();
            }
        }
    }

    static void dohrano()
    {
        Window::hwnd = hwnd;

        RECT rect;
        GetClientRect(hwnd, &rect);

        int centerX = (rect.right - BUTTON_WIDTH) / 2;
        int centerY = (rect.bottom - BUTTON_HEIGHT) / 2;

        hwndLabelVitez = CreateWindowEx(
            0, L"STATIC", L"",
            WS_CHILD | WS_VISIBLE | SS_CENTER,
            centerX, 0.9 * rect.bottom - TRACKBAR_HEIGHT, TRACKBAR_WIDTH, 3 * LABEL_HEIGHT,
            Window::hwnd, NULL, (HINSTANCE)GetWindowLongPtr(Window::hwnd, GWLP_HINSTANCE), NULL);

        switch (Hraci_plocha.vitez)
        {
        case 0:
        {
            std::wstring valueText = L"REMÍZA!";
            SetWindowText(hwndLabelVitez, valueText.c_str());
            break;
        }
        case 1:
        {
            std::wstring valueText = L"KOLEÈKA VYHRÁLA!";
            SetWindowText(hwndLabelVitez, valueText.c_str());
            break;
        }
        case 2:
        {
            std::wstring valueText = L"ZVÍTÌZILY KØÍŽKY!";
            SetWindowText(hwndLabelVitez, valueText.c_str());
            break;
        }
        }

        LOGFONT lf = {};
        lf.lfHeight = 30;
        lstrcpy(lf.lfFaceName, L"Bahnschrift SemiLight");
        HFONT hFont = CreateFontIndirect(&lf);

        SendMessage(hwndLabelVitez, WM_SETFONT, (WPARAM)hFont, TRUE);

        hwndButtonRestart = CreateWindow(
            L"BUTTON",
            L"Nová hra",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            0.1*rect.right,
            0.9 * rect.bottom - TRACKBAR_HEIGHT,
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            hwnd,
            (HMENU)3,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            nullptr);

        hwndButtonKonec = CreateWindow(
            L"BUTTON",
            L"Konec hry",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            0.9*rect.right - BUTTON_WIDTH,
            0.9 * rect.bottom - TRACKBAR_HEIGHT,
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            hwnd,
            (HMENU)6,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            nullptr);
    }

    static void vyber_hrace() {
        int centerX;
        int centerY;

        RECT rect;
        GetClientRect(Window::hwnd, &rect);

        centerX = (rect.right - TRACKBAR_WIDTH) / 2;
        centerY = (rect.bottom - TRACKBAR_HEIGHT) / 2;

        hwndTrackbarHeigth = CreateWindowEx(
            0, TRACKBAR_CLASS, NULL,
            WS_CHILD | WS_VISIBLE | TBS_HORZ,
            centerX, centerY, TRACKBAR_WIDTH, TRACKBAR_HEIGHT,
            Window::hwnd, NULL, (HINSTANCE)GetWindowLongPtr(Window::hwnd, GWLP_HINSTANCE), NULL);

        SendMessage(hwndTrackbarHeigth, TBM_SETRANGE, TRUE, MAKELPARAM(TRACKBAR_MIN, TRACKBAR_MAX_H));
        SendMessage(hwndTrackbarHeigth, TBM_SETPOS, TRUE, TRACKBAR_MIN);  

        hwndTrackbarWidth = CreateWindowEx(
            0, TRACKBAR_CLASS, NULL,
            WS_CHILD | WS_VISIBLE | TBS_HORZ,
            centerX, centerY - (TRACKBAR_HEIGHT + LABEL_HEIGHT), TRACKBAR_WIDTH, TRACKBAR_HEIGHT,
            Window::hwnd, NULL, (HINSTANCE)GetWindowLongPtr(Window::hwnd, GWLP_HINSTANCE), NULL);

        SendMessage(hwndTrackbarWidth, TBM_SETRANGE, TRUE, MAKELPARAM(TRACKBAR_MIN, TRACKBAR_MAX_W));
        SendMessage(hwndTrackbarWidth, TBM_SETPOS, TRUE, TRACKBAR_MIN); 

        hwndTrackbarCon = CreateWindowEx(
            0, TRACKBAR_CLASS, NULL,
            WS_CHILD | WS_VISIBLE | TBS_HORZ,
            centerX, centerY + TRACKBAR_HEIGHT + LABEL_HEIGHT, TRACKBAR_WIDTH, TRACKBAR_HEIGHT,
            Window::hwnd, NULL, (HINSTANCE)GetWindowLongPtr(Window::hwnd, GWLP_HINSTANCE), NULL);

        SendMessage(hwndTrackbarCon, TBM_SETRANGE, TRUE, MAKELPARAM(TRACKBAR_MIN, TRACKBAR_MAX_C));
        SendMessage(hwndTrackbarCon, TBM_SETPOS, TRUE, TRACKBAR_MIN_Alt);

        hwndLabelWidth = CreateWindowEx(
            0, L"STATIC", L"Šíøka hrací plochy", 
            WS_CHILD | WS_VISIBLE | SS_CENTER, 
            centerX, centerY - 2*TRACKBAR_HEIGHT, TRACKBAR_WIDTH, LABEL_HEIGHT,
            Window::hwnd, NULL, (HINSTANCE)GetWindowLongPtr(Window::hwnd, GWLP_HINSTANCE), NULL);

        hwndLabelHeigth = CreateWindowEx(
            0, L"STATIC", L"Výška hrací plochy",
            WS_CHILD | WS_VISIBLE | SS_CENTER,
            centerX, centerY - LABEL_HEIGHT, TRACKBAR_WIDTH, LABEL_HEIGHT,
            Window::hwnd, NULL, (HINSTANCE)GetWindowLongPtr(Window::hwnd, GWLP_HINSTANCE), NULL);

        hwndLabelCon = CreateWindowEx(
            0, L"STATIC", L"Poèet pozic potøebných k vítìzství",
            WS_CHILD | WS_VISIBLE | SS_CENTER,
            centerX, centerY + TRACKBAR_HEIGHT, TRACKBAR_WIDTH, LABEL_HEIGHT,
            Window::hwnd, NULL, (HINSTANCE)GetWindowLongPtr(Window::hwnd, GWLP_HINSTANCE), NULL);
        
        hwndWidth = CreateWindow(
            L"STATIC",
            L"3",  
            WS_CHILD | WS_VISIBLE | SS_CENTER,  
            (rect.right - TRACKBAR_HEIGHT + LABEL_HEIGHT) / 2 + TRACKBAR_WIDTH / 2 + 12,
            centerY - 2*LABEL_HEIGHT - TRACKBAR_HEIGHT,  
            2 * (TRACKBAR_HEIGHT + LABEL_HEIGHT),
            TRACKBAR_HEIGHT + LABEL_HEIGHT, 
            Window::hwnd,  
            nullptr, 
            (HINSTANCE)GetWindowLongPtr(Window::hwnd, GWLP_HINSTANCE),
            nullptr);

        hwndHeigth = CreateWindow(
            L"STATIC",
            L"3",
            WS_CHILD | WS_VISIBLE | SS_CENTER,
            (rect.right - TRACKBAR_HEIGHT + LABEL_HEIGHT) / 2 + TRACKBAR_WIDTH / 2 + 12,
            centerY - LABEL_HEIGHT,
            2 * (TRACKBAR_HEIGHT + LABEL_HEIGHT),
            TRACKBAR_HEIGHT + LABEL_HEIGHT,
            Window::hwnd,
            nullptr,
            (HINSTANCE)GetWindowLongPtr(Window::hwnd, GWLP_HINSTANCE),
            nullptr);

        hwndcon = CreateWindow(
            L"STATIC",
            L"3",
            WS_CHILD | WS_VISIBLE | SS_CENTER,
            (rect.right - TRACKBAR_HEIGHT + LABEL_HEIGHT) / 2 + TRACKBAR_WIDTH / 2 + 12,
            centerY + TRACKBAR_HEIGHT,
            2*(TRACKBAR_HEIGHT + LABEL_HEIGHT),
            (TRACKBAR_HEIGHT + LABEL_HEIGHT),
            Window::hwnd,
            nullptr,
            (HINSTANCE)GetWindowLongPtr(Window::hwnd, GWLP_HINSTANCE),
            nullptr);

        hwndButtonZacit = CreateWindow(
            L"BUTTON",
            L"ZAÈIT HRU",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            centerX,
            centerY + 5*TRACKBAR_HEIGHT,
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            hwnd,
            (HMENU)3,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            nullptr);

        LOGFONT lf = {};
        lf.lfHeight = 36;
        lstrcpy(lf.lfFaceName, L"Arial");
        HFONT hFont = CreateFontIndirect(&lf);

        SendMessage(hwndWidth, WM_SETFONT, (WPARAM)hFont, TRUE);
        SendMessage(hwndHeigth, WM_SETFONT, (WPARAM)hFont, TRUE);
        SendMessage(hwndcon, WM_SETFONT, (WPARAM)hFont, TRUE);
    }

    static void DrawTable(HDC hdc, const RECT& clientRect) {

        if (!nakreslit)
        {
            return;
        }

        Window::hwnd = hwnd;

        RECT rect;
        GetClientRect(hwnd, &rect);

        int tableWidth = mensi(0.8 * rect.right, 100 * Hraci_plocha.width);
        int tableHeight = mensi(0.6 * rect.bottom, 100 * Hraci_plocha.heigth);

        int cellWidth = tableWidth / Hraci_plocha.width;
        int cellHeight = tableHeight / Hraci_plocha.heigth;

        RECT tableRect = {
            clientRect.left + (clientRect.right - clientRect.left - tableWidth) / 2,
            clientRect.top + (clientRect.bottom - clientRect.top - tableHeight) / 2,
            clientRect.left + (clientRect.right - clientRect.left + tableWidth) / 2,
            clientRect.top + (clientRect.bottom - clientRect.top + tableHeight) / 2
        };

        for (int row = 0; row < Hraci_plocha.heigth; ++row) 
        {
            for (int col = 0; col < Hraci_plocha.width; ++col) 
            {
                RECT cellRect = {
                    tableRect.left + col * cellWidth,
                    tableRect.top + row * cellHeight,
                    tableRect.left + (col + 1) * cellWidth,
                    tableRect.top + (row + 1) * cellHeight
                };

                FrameRect(hdc, &cellRect, (HBRUSH)GetStockObject(WHITE_BRUSH));

                int centerX = (cellRect.left + cellRect.right) / 2;
                int centerY = (cellRect.top + cellRect.bottom) / 2;
                int radius = min(cellWidth, cellHeight) / 4;
                int pos = row * Hraci_plocha.width + col + 1; 

                HPEN hPen;
                HPEN hOldPen;

                if (Hraci_plocha.plocha [row][col] == 79) 
                { 

                    if (nejnovejsiX == col and nejnovejsiY == row)
                    {
                        hPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
                        hOldPen = (HPEN)SelectObject(hdc, hPen);
                    }
                    else
                    {
                        hPen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
                        hOldPen = (HPEN)SelectObject(hdc, hPen);
                    }

                    Ellipse(hdc, centerX - radius, centerY - radius, centerX + radius, centerY + radius);

                    SelectObject(hdc, hOldPen);
                    DeleteObject(hPen);
                }
                else if (Hraci_plocha.plocha[row][col] == 120) 
                { 

                    if (nejnovejsiX == col and nejnovejsiY == row)
                    {
                        hPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
                        hOldPen = (HPEN)SelectObject(hdc, hPen);
                    }
                    else
                    {
                        hPen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
                        hOldPen = (HPEN)SelectObject(hdc, hPen);
                    }

                    MoveToEx(hdc, centerX - radius, centerY - radius, nullptr);
                    LineTo(hdc, centerX + radius, centerY + radius);
                    MoveToEx(hdc, centerX - radius, centerY + radius, nullptr);
                    LineTo(hdc, centerX + radius, centerY - radius);

                    SelectObject(hdc, hOldPen);
                    DeleteObject(hPen);
                }
            }
        }

        DrawRowLabels(hdc, tableRect, cellWidth, cellHeight);
        DrawColumnLabels(hdc, tableRect, cellWidth, cellHeight);
    }

    static void DrawRowLabels(HDC hdc, const RECT& tableRect, int cellWidth, int cellHeight) {
        for (int i = 0; i < Hraci_plocha.heigth; ++i) 
        {
            RECT labelRect = {
                tableRect.left - cellWidth,
                tableRect.top + i * cellHeight,
                tableRect.left,
                tableRect.top + (i + 1) * cellHeight
            };

            std::wstring labelText = std::to_wstring(i + 1);
            DrawTextW(hdc, labelText.c_str(), -1, &labelRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        }
    }

    static void DrawColumnLabels(HDC hdc, const RECT& tableRect, int cellWidth, int cellHeight) {
        for (int i = 0; i < Hraci_plocha.width; ++i) {
            RECT labelRect = {
                tableRect.left + i * cellWidth,
                tableRect.top - cellHeight/2,
                tableRect.left + (i + 1) * cellWidth,
                tableRect.top
            };

            std::wstring labelText = std::wstring(1, L'A' + i);
            DrawTextW(hdc, labelText.c_str(), -1, &labelRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        }
    }

    bool Create(HINSTANCE hInstance, int nCmdShow) {
        const wchar_t CLASS_NAME[] = L"Piškvorky";

        WNDCLASS wc = {};
        wc.lpfnWndProc = WindowProc;
        wc.hInstance = hInstance;
        wc.lpszClassName = CLASS_NAME;

        RegisterClass(&wc);

        HWND hwnd = CreateWindowEx(
            0,
            CLASS_NAME,
            L"Piškvorky",
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
            nullptr,
            nullptr,
            hInstance,
            nullptr
        );

        if (hwnd == nullptr) {
            return false;
        }

        ShowWindow(hwnd, nCmdShow);
        return true;
    }
};

HWND Window::hwnd = nullptr;