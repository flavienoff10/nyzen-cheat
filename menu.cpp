#define IMGUI_DEFINE_MATH_OPERATORS
#include "menu.hpp"
#include <cstring> // Für die Verwendung von strstr
#include "../dependencies/imgui/imgui.h"
#include "../dependencies/imgui/imgui_impl_win32.h"

#include "../utils/utils.hpp"
#include "../hooks/hooks.hpp"


#include "../fivem/features/aimbot.hpp"
#include "../fivem/features/visuals.hpp"
#include "../fivem/features/weapon.hpp"
#include "../fivem/features/self.hpp"

#include "../fivem/settings/settings.hpp"
#include "C:\Users\testf\Desktop\Cheat\FiveM\Nyzen\UniversalHookX\src\fivem\content\classes.hpp"

#include "C:\Users\testf\Desktop\Cheat\FiveM\Nyzen\UniversalHookX\src\fivem\settings\settings.hpp"


//#include "C:\Users\yusei\Desktop\Yusei.cc Internal\UniversalHookX\src\skStr.h"

#include "../fivem/features/lootbag.hpp"
#include "../fivem/features/vehicles.hpp"
#include "../../trebucbd.h"
#include "../../IconsFontAwesome6.h"

#include "C:\Users\testf\Desktop\Cheat\FiveM\Nyzen\UniversalHookX\src\backend.hpp"
#include "C:\Users\testf\Desktop\Cheat\FiveM\Nyzen\UniversalHookX\src\hwid.h"
#include "../dependencies/imgui/notifications.hpp"
#include "../auth/auth.hpp"
#include <string>

static int selected_index = 1;
static int selectedVeh_index = 1;
using namespace ImGui;
char key_auth[16] = "";


void DrawHelpText(const char* helpText) {
    if (ImGui::IsItemHovered()) {
        ImGui::BeginTooltip();
        ImGui::Text("%s", helpText);
        ImGui::EndTooltip();
    }
}






#define ALPHA (ImGuiColorEditFlags_AlphaPreview | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_InputRGB | ImGuiColorEditFlags_Float | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_PickerHueBar | ImGuiColorEditFlags_NoBorder)
#define NO_ALPHA (ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoAlpha | ImGuiColorEditFlags_InputRGB | ImGuiColorEditFlags_Float | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_PickerHueBar | ImGuiColorEditFlags_NoBorder)

bool draw_demo = false;

int selected_cfg = 0;
const char* cfg[]{ "Slot 1", "Slot 2", "Slot 3", "Slot 4", "Slot 5", "Slot 6", "Slot 7", "Slot 8", "Slot 9", "Slot 10" };

int current_tabs = 1;

char font[200] = "";

bool register_mode = false;



DWORD weaponsLlist[] = {
    0x93E220BD, 0xA0973D5E, 0x24B17070, 0x2C3731D9, 0xAB564B93, 0x787F0BB, 0xBA45E8B8, 0x23C9F95C, 0xFDBC8A50, 0x497FACC3, //Throwables
    0x34A67B97, 0xFBAB5776, 0x060EC506, //Miscellaneous
    0xB1CA77B1, 0xA284510B, 0x42BF8A85, 0x7F7497E5, 0x6D544C99, 0x63AB0442, 0x0781FE4A, 0xB62D1F67, //Heavy Weapons
    0x05FC3C11, 0x0C472FE2, 0xA914799, 0xC734385A, 0x6A6C02E0, //Sniper Rifles
    0x9D07F764, 0x7FD62962, 0xDBBD7280, 0x61012683, //Light Machine Guns
    0xBFEFFF6D, 0x394F415C, 0x83BF0278, 0xFAD1F1C9, 0xAF113F99, 0xC0A3098D, 0x969C3D67, 0x7F229F94, 0x84D6FAFD, 0x624FE830, //Assault Rifles
    0x13532244, 0x2BE6766B, 0x78A97CD0, 0xEFE7E2DF, 0x0A3D4D34, 0xDB1AA450, 0xBD248B55, 0x476BF155, //Submachine Guns
    0x1B06D571, 0xBFE256D4, 0x5EF9FEC4, 0x22D8FE39, 0x3656C8C1, 0x99AEEB3B, 0xBFD21232, 0x88374054, 0xD205520E, 0x83839C4, 0x47757124, 0xDC4DB296, 0xC1B3C3D1, 0xCB96392F, 0x97EA20B8, 0xAF3696A1, //Pistols
    0x92A27487, 0x958A4A8F, 0xF9E6AA4B, 0x84BD7BFD, 0x8BB05FD7, 0x440E4788, 0x4E875F73, 0xF9DCBF2D, 0xD8DF3C3C, 0x99B507EA, 0xDD5DF8D9, 0xDFE37640, 0x678B81B1, 0x19044EE0, 0xCD274149, 0x94117305, 0x3813FC08, //Mele
    0x1D073A89, 0x555AF99A, 0x7846A318, 0xE284C527, 0x9D61E50F, 0xA89CB99E, 0x3AABBBAA, 0xEF951FBB, 0x12E82D3D
};

const char* weaponType[]{ "Throwable", "Misc", "Heavy", "Sniper", "Pistol", "Melee", "Light", "SMG", "Rifle", "Shotgun", "Unknown" };


bool myCheckboxValue = false; // Hier wird der Status der Checkbox gespeichert



static bool checkboxValue = false;

std::string name = E("NaX");                                                             // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = E("pYOZ3XOesH");                                                            // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = E("346140f59374154908c805a1b87151fa7e815361fd0a803ac1d75f8f29c4e1eb"); // app secret, the blurred text on licenses tab and other tabs
std::string version = E("1.0");                                                                   // leave alone unless you've changed version on website
std::string url = E("https://keyauth.win/api/1.2/");                                        // change if you're self-hosting
std::string sslPin = E("ssl pin key (optional)");                                      // don't change unless you intend to pin public certificate key. you can get here in the "Pin SHA256" field https://www.ssllabs.com/ssltest/analyze.html?d=keyauth.win&latest. If you do this you need to be aware of when SSL key expires so you can update it

using namespace KeyAuth;
api KeyAuthApp(name, ownerid, secret, version, url, sslPin);

//loader
char username[255] = "";
char key[50] = "";
static char password[25] = "";

ImFont* fonti;
//save caca
FILE* p_stream;

bool loaded = true;

// security
//int tired = 3;
int auth = 2;
int checking = 0;
bool draw_menu = true;




bool ShowMessageBox(const char* title, const char* message) {
    bool result = false;

    // ImGui-Initialisierung (du solltest sicherstellen, dass ImGui korrekt eingerichtet ist)
    // ...

    // Hauptprogramm-Schleife
    while (true) {
        // ImGui-Frame starten
        ImGui::Begin(title, nullptr, ImGuiWindowFlags_AlwaysAutoResize);

        // MessageBox-Text anzeigen
        ImGui::Text("%s", message);

        // Schaltfl채chen f체r Best채tigen/Abbrechen
        if (ImGui::Button("OK", ImVec2(120, 0))) {
            result = true;
            break;
        }

        ImGui::SameLine();

        if (ImGui::Button("Abbrechen", ImVec2(120, 0))) {
            result = false;
            break;
        }

        // ImGui-Frame beenden
        ImGui::End();

        // Hier m체ssten normalerweise die ImGui-Render- und Event-Handling-Schritte erfolgen.
        // ...

        // Hier wird die Schleife fortgesetzt oder beendet, je nach Programmlogik.
        // ...
    }

    // ImGui-Ressourcen freigeben (wenn notwendig)
    // ...

    return result;
}



ImFont* AddCustomDefaultFont(const ImFontConfig* font_cfg_template) {
    ImGuiIO& io = ImGui::GetIO();
    (void)io;

    ImFontConfig font_cfg = font_cfg_template ? *font_cfg_template : ImFontConfig();
    if (!font_cfg_template) {
        font_cfg.OversampleH = font_cfg.OversampleV = 1;
        font_cfg.PixelSnapH = true;
    }
    if (font_cfg.SizePixels <= 0.0f)
        font_cfg.SizePixels = 13.0f * 1.0f;
    if (font_cfg.Name[0] == '\0')
        ImFormatString(font_cfg.Name, IM_ARRAYSIZE(font_cfg.Name), "ProggyClean.ttf, %dpx", (int)font_cfg.SizePixels);
    font_cfg.EllipsisChar = (ImWchar)0x0085;
    font_cfg.GlyphOffset.y = 1.0f * IM_FLOOR(font_cfg.SizePixels / 13.0f); // Add +1 offset per 13 units

    // const char* ttf_compressed_base85 = GetDefaultCompressedFontDataTTFBase85();
    const ImWchar* glyph_ranges = font_cfg.GlyphRanges != NULL ? font_cfg.GlyphRanges : io.Fonts->GetGlyphRangesDefault();
    // ImFont* font = io.Fonts->AddFontFromMemoryCompressedTTF(trebucbd_compressed_data, trebucbd_compressed_size, font_cfg.SizePixels, &font_cfg, glyph_ranges);

    ImFont* font = io.Fonts->AddFontFromMemoryCompressedTTF(trebucbd_compressed_data, sizeof(trebucbd_compressed_size), 14.f, nullptr, glyph_ranges);
    return font;
}

#include "../dependencies/imgui/custom.hpp"
#include "../dependencies/imgui/bytes.hpp"

#include <C:\Users\testf\Desktop\Cheat\FiveM\Nyzen\UniversalHookX\src\fivem\features\Teleport.h>
#include <C:\Users\testf\Desktop\Cheat\FiveM\Nyzen\UniversalHookX\src\fivem\features\confighigjdgsijfhsdgihsdjgihsdjfhsdjfhsdpijsdfhpoihsdjpohsdjdhsopj.h>
#include "C:\Users\testf\Desktop\Cheat\FiveM\Nyzen\UniversalHookX\src\fivem\features\Teleport.h"



namespace Menu {



    void InitializeContext(HWND hwnd) {
        if (ImGui::GetCurrentContext())
            return;

        ImGui::CreateContext();
        ImGui_ImplWin32_Init(hwnd);
        ImGuiStyle* Style = &ImGui::GetStyle();
        ImVec4* Colors = Style->Colors;
        ImGui::StyleColorsDark();



        ImFontConfig font_config;
        font_config.PixelSnapH = false;
        font_config.FontDataOwnedByAtlas = false;
        font_config.OversampleH = 5;
        font_config.OversampleV = 5;
        font_config.RasterizerMultiply = 1.2f;

        static const ImWchar ranges[] = {

        0x0020, 0x00FF, // Basic Latin + Latin Supplement
        0x0400, 0x052F, // Cyrillic + Cyrillic Supplement
        0x2DE0, 0x2DFF, // Cyrillic Extended-A
        0xA640, 0xA69F, // Cyrillic Extended-B
        0xE000, 0xE226, // icons
        0,
        };

        ImGuiIO& io = ImGui::GetIO();
        io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\segoeui.ttf", 17, &font_config, ranges);
        io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\segoeuib.ttf", 18, &font_config, ranges);
        io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\segoeuib.ttf", 25, &font_config, ranges);
        io.IniFilename = io.LogFilename = nullptr;



        font_config.GlyphRanges = ranges;
        AddCustomDefaultFont(nullptr);

        // merge in icons from Font Awesome
        io.Fonts->AddFontFromMemoryTTF(icons_binary, sizeof icons_binary, 19, &font_config, ranges);
        static const ImWchar icons_ranges[] = { ICON_MIN_FA, ICON_MAX_16_FA, 0 };

        ImFontConfig icons_config;
        icons_config.MergeMode = true;
        icons_config.PixelSnapH = true;
        ImFont* FontAwesome = io.Fonts->AddFontFromMemoryCompressedTTF(fa6_solid_compressed_data, fa6_solid_compressed_size, 14.f, &icons_config, icons_ranges);
        ImFont* FontAwesomeBig = io.Fonts->AddFontFromMemoryCompressedTTF(fa6_solid_compressed_data, fa6_solid_compressed_size, 19.f, nullptr, icons_ranges);

        ImFont* TitleFont = io.Fonts->AddFontFromMemoryCompressedTTF(trebucbd_compressed_data, trebucbd_compressed_size, 30, nullptr, io.Fonts->GetGlyphRangesDefault());


    }


    bool ShowMessageBox(const char* title, const char* message, const char* button1, const char* button2)
    {
        bool result = false;
        ImGui::OpenPopup(title);

        if (ImGui::BeginPopupModal(title, NULL, ImGuiWindowFlags_AlwaysAutoResize))
        {
            ImGui::Text(message);

            if (ImGui::Button(button1))
            {
                result = true;
                ImGui::CloseCurrentPopup();
            }

            if (button2 != NULL && ImGui::Button(button2))
            {
                result = false;
                ImGui::CloseCurrentPopup();
            }

            ImGui::EndPopup();
        }

        return result;
    }

    const char* stristr(const char* str1, const char* str2) {
        const char* ptr = str1;
        const char* substr;
        while (*ptr != '\0') {
            substr = str2;
            while (*ptr != '\0' && *substr != '\0' && tolower(*ptr) == tolower(*substr)) {
                ++ptr;
                ++substr;
            }
            if (*substr == '\0') return str1;
            if (*ptr == '\0') return nullptr;
            ++str1;
            ptr = str1;
        }
        return nullptr;
    }

    int N = 160;
    int lineMaxDist = 1800;
    ImColor lineCol = { 255, 255, 255, 8 };
    float lineThickness = 1.0f;

    void setupPoints(std::vector<std::pair<ImVec2, ImVec2>>& n) {
        ImVec2 screenSize(ImGui::GetIO().DisplaySize);
        for (auto& p : n)
            p.second = p.first = ImVec2(rand() % (int)screenSize.x, rand() % (int)screenSize.y);
    }
    float length(ImVec2 x) { return x.x * x.x + x.y * x.y; }
    void FX(ImDrawList* d, ImVec2 b, float speedMultiplier)
    {

        const int N = 100; // Annahme: Setze die gew체nschte Gr철횩e f체r den Vektor points

        static std::vector<std::pair<ImVec2, ImVec2>> size(N);
        static auto once = (setupPoints(size), true);
        float Dist;

        for (auto& p : size) {
            Dist = sqrt(length(p.first - p.second));
            if (Dist > 0) {
                p.first += (p.second - p.first) / Dist * speedMultiplier; // Geschwindigkeit anpassen
            }
            if (Dist < 4 || rand() % 100 == 0) { // 횆ndere die Bedingung f체r Zufallspositionierung
                p.second = ImVec2(rand() % (int)b.x, rand() % (int)b.y);
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                Dist = length(size[i].first - size[j].first);
                if (Dist < lineMaxDist) {
                    d->AddLine(GetWindowPos() + size[i].first, GetWindowPos() + size[j].first, custom.get_accent_colorparticles(), lineThickness);
                }
            }
        }
    }

   


    void Render() {

        
        

        if (loaded == false) {

            

            KeyAuthApp.init(); 


                std::ifstream inFile("C:\\WINDOWS\\pizza.txt");
                if (inFile.is_open())
                {
                    std::string username;
                    std::getline(inFile, username);
                    std::string password;
                    std::getline(inFile, password);



                    if (!username.empty() == '\r')
                        username.pop_back();

                    if (!password.empty() == '\r')
                        password.pop_back();

                    if (!username.empty() || !password.empty())
                    {
                        KeyAuthApp.login(username , password);
                    //    if (KeyAuthApp.data.success)
                        {
                            loaded = true;
                            auth = 2;
                            notifications.add("Succesfully Loaded");
                        }
                //        else
                      //  {

                           // MessageBoxA(0, KeyAuthApp.data.message.c_str(), E("Error"), MB_OK | MB_ICONERROR);

                    //    }
                    }
                }


        }


        //if (tired == 3)
        //{

        //    ImGuiIO& io = ImGui::GetIO();

            //auto windows_x = io.DisplaySize.x / 2;
            //auto windows_y = io.DisplaySize.y / 2; // HAST DU NH AUTH DRIN ?

       /*     auto myWindowX = windows_x - 150 / 2;
            auto myWindowY = windows_y - 150 / 2;*/

        //    ImGui::SetNextWindowPos(ImVec2(700, 300));
        //    ImGui::SetNextWindowSize(ImVec2(450, 480));

        //    if (ImGui::Begin("##Login", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize)) {

        //        ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 255, 255, 255));
        //        ImGui::Text("Phantom");
        //        ImGui::PopStyleColor();
        //        

        //        ImGui::Text(E("Username"));
        //        ImGui::InputText(E("##name"), username, IM_ARRAYSIZE(username));

        //        ImGui::Text(E("Password"));
        //        ImGui::InputText(E("##Password"), password, IM_ARRAYSIZE(password), ImGuiInputTextFlags_Password);

        //        if (register_mode) {

        //            ImGui::Text(E("License"));
        //            ImGui::InputText(E("##License"), key, IM_ARRAYSIZE(key));
        //        }

        //        ImGui::Spacing();444

        //        Checkbox("Register ##aaa", &register_mode);

        //        ImGui::Spacing();

        //        if (!register_mode) {

        //            if (ImGui::Button(E("Login"), ImVec2(165, 27))) {


        //            }

        //        }
        //        else {

        //            if (ImGui::Button(E("Register"), ImVec2(165, 27))) {


        //            }
        //        }
        //    }
        //    ImGui::End();
        //   
        //}




        if (loaded) {

            if (auth == 2) {

               /* if (settings::dd::watermark) {

                    if (settings::misc::watermark) {

                        std::string text = E("Easy public - 2.0.0 - ") + std::string(__DATE__) + E(" beta version logged at : user");

                        ImGui::GetForegroundDrawList()->AddText(ImVec2(10, ImGui::GetIO().DisplaySize.y - 25), ImColor(255, 255, 255, 255), text.c_str());*/
                

                if (draw_menu) {




                    aimbot::hook();
                   /* weapon::initsilent();*/
                    visuals::player_esp();
                    hook::vehicle();

                    visuals::lootbag();
                    weapon::hook();
                    self::options();
                    self::noclip();
                   /* self::autofarm();*/


                    if (settings::visuals::draw_fov) {

                        if (settings::visuals::filled_fov) {
                            ImGui::GetBackgroundDrawList()->AddCircleFilled(ImVec2(FiveM::WindowSize.x / 2, FiveM::WindowSize.y / 2), settings::aimbot::aimbot_fov1 * 10, ImColor(0, 0, 0, 90), 100.0f);
                            ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(FiveM::WindowSize.x / 2, FiveM::WindowSize.y / 2), settings::aimbot::aimbot_fov1 * 10, settings::visuals::fov_color, 100.0f);
                        }
                        else {

                            ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(FiveM::WindowSize.x / 2, FiveM::WindowSize.y / 2), settings::aimbot::aimbot_fov1 * 10, settings::visuals::fov_color, 100.0f);
                        }
                    }

                    if (settings::visuals::crosshair) {
                        if (settings::visuals::crossahir_style == 0) {

                            auto draw = ImGui::GetBackgroundDrawList();
                            draw->AddCircle(ImVec2(FiveM::WindowSize.x / 2, FiveM::WindowSize.y / 2), 2, settings::visuals::crosshair_color, 0, 3.0f);
                            draw->AddCircle(ImVec2(FiveM::WindowSize.x / 2, FiveM::WindowSize.y / 2), 2, settings::visuals::crosshair_color, 0, 3.0f);
                        }

                        if (settings::visuals::crossahir_style == 1) {

                            auto draw = ImGui::GetBackgroundDrawList();
                            draw->AddCircle(ImVec2(FiveM::WindowSize.x / 2, FiveM::WindowSize.y / 2), 3, settings::visuals::crosshair_color, 100, 0.0f);
                        }

                        if (settings::visuals::crossahir_style == 2) {

                            auto draw = ImGui::GetBackgroundDrawList();

                            auto drx = FiveM::WindowSize.x / 2;
                            auto dry = FiveM::WindowSize.y / 2;

                            draw->AddLine({ drx - 10, dry }, { drx + 10, dry }, settings::visuals::crosshair_color);
                            draw->AddLine({ drx, dry - 10 }, { drx, dry + 10 }, settings::visuals::crosshair_color);
                        }

                        if (settings::visuals::crossahir_style == 3) {

                            auto draw = ImGui::GetBackgroundDrawList();
                            ImVec2 center(FiveM::WindowSize.x / 2, FiveM::WindowSize.y / 2);
                            float size = 5.0f;
                            ImU32 color = settings::visuals::crosshair_color;

                            ImVec2 p1(center.x, center.y - size);
                            ImVec2 p2(center.x - size * 0.866f, center.y + size * 0.5f);
                            ImVec2 p3(center.x + size * 0.866f, center.y + size * 0.5f);

                            draw->AddTriangle(p1, p2, p3, color, 3.0f);
                            draw->AddTriangleFilled(p1, p2, p3, color);
                        }





                        if (settings::visuals::crossahir_style == 4) {

                            auto draw = ImGui::GetBackgroundDrawList();
                            ImVec2 center = ImVec2(FiveM::WindowSize.x / 2, FiveM::WindowSize.y / 2);
                            float size = 5.0f;

                            draw->AddLine(ImVec2(center.x - size, center.y), ImVec2(center.x + size, center.y), settings::visuals::crosshair_color, 3.0f);
                            draw->AddLine(ImVec2(center.x - size, center.y + 1), ImVec2(center.x + size, center.y + 1), settings::visuals::crosshair_color, 3.0f);
                            draw->AddLine(ImVec2(center.x - size, center.y - 1), ImVec2(center.x + size, center.y - 1), settings::visuals::crosshair_color, 3.0f);


                            draw->AddLine(ImVec2(center.x, center.y - size), ImVec2(center.x, center.y + size), settings::visuals::crosshair_color, 3.0f);
                            draw->AddLine(ImVec2(center.x + 1, center.y - size), ImVec2(center.x + 1, center.y + size), settings::visuals::crosshair_color, 3.0f);
                            draw->AddLine(ImVec2(center.x - 1, center.y - size), ImVec2(center.x - 1, center.y + size), settings::visuals::crosshair_color, 3.0f);
                        }
                    }

                    if (settings::visuals::watermark) {
                        auto draw_list = ImGui::GetBackgroundDrawList();

                        auto watermark = E(" Nyzen - Beta");

                        std::string text = E("") + std::string(__DATE__) + E("");

                        ImGui::GetForegroundDrawList()->AddText(ImVec2(8, ImGui::GetIO().DisplaySize.y - 25), ImColor(255, 255, 255, 255), text.c_str());
                        auto watermark_size = ImGui::CalcTextSize(watermark);

                        auto yOffset = 0;
                        auto offset = 1.0; // Ändere die Offset-Größe nach Bedarf für eine dickere Umrandung

                        // Draw the watermark with thicker outline
                        draw_list->AddText(ImVec2(10, 6 + yOffset), ImColor(0, 0, 0, 255), watermark);
                        draw_list->AddText(ImVec2(10 + offset, 6 + yOffset), ImColor(0, 0, 0, 255), watermark);
                        draw_list->AddText(ImVec2(10 - offset, 6 + yOffset), ImColor(0, 0, 0, 255), watermark);
                        draw_list->AddText(ImVec2(10, 6 + offset + yOffset), ImColor(0, 0, 0, 255), watermark);
                        draw_list->AddText(ImVec2(10, 6 - offset + yOffset), ImColor(0, 0, 0, 255), watermark);

                        // Draw the username with the same thicker outline
            //            const char* username = KeyAuthApp.data.username.c_str();
                        std::string fullWatermark = std::string(watermark) + " " + username;
                        auto fullWatermark_size = ImGui::CalcTextSize(fullWatermark.c_str());
                        draw_list->AddText(ImVec2(10, 6 + yOffset), ImColor(0, 0, 0, 255), fullWatermark.c_str());
                        draw_list->AddText(ImVec2(10 + offset, 6 + yOffset), ImColor(0, 0, 0, 255), fullWatermark.c_str());
                        draw_list->AddText(ImVec2(10 - offset, 6 + yOffset), ImColor(0, 0, 0, 255), fullWatermark.c_str());
                        draw_list->AddText(ImVec2(10, 6 + offset + yOffset), ImColor(0, 0, 0, 255), fullWatermark.c_str());
                        draw_list->AddText(ImVec2(10, 6 - offset + yOffset), ImColor(0, 0, 0, 255), fullWatermark.c_str());

                        // Draw the complete watermark text
                        draw_list->AddText(ImVec2(10, 6 + yOffset), ImColor(255, 255, 255, 255), fullWatermark.c_str());






                        
                    }



                    if (SAFE_CALL(GetAsyncKeyState)(settings::self::hotkey_noclip) & 1) {

                        settings::self::noclip = !settings::self::noclip;
                    }
                    if (SAFE_CALL(GetAsyncKeyState)(VK_F5) & 0x8000) {
                        settings::self::freecam = !settings::self::freecam;
                    }

                    if (SAFE_CALL(GetAsyncKeyState)(settings::self::hotkey_vehclip) & 1) {

                        settings::vehicle::vehclip = !settings::vehicle::vehclip;
                    }


                }
            }
        }
        else {

            exit(3);
        }


        ImGui::GetIO().MouseDrawCursor = bShowMenu;

        if (!bShowMenu)
            return;


        if (loaded) {

            if (auth == 1) {




                ImGuiIO& io = ImGui::GetIO(); (void)io;
                io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
                io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

                static bool bools[50];
                static int  ints[50];
                vector < const char* > items = { "Variant", "Variant 1", "Variant 2", "Variant 3" };
                static char buf[64];

                static float color[4] = { 1.f, 1.f, 1.f, 1.f };

                PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));

                ImGui::Begin("logintab", NULL, ImGuiWindowFlags_NoDecoration); {
                    auto window = GetCurrentWindow();
                    auto draw = window->DrawList;
                    auto pos = window->Pos;
                    auto size = window->Size;

                    SetWindowSize(custom.window_size);

                    FX(draw, size, 0.20f);

                    custom.m_anim = ImLerp(custom.m_anim, 1.f, 0.04f);

                    draw->AddRectFilled(pos, pos + ImVec2(size.x, 55), ImColor(18, 18, 18), GetStyle().WindowRounding, ImDrawFlags_RoundCornersTop);

                    ImVec2 text_size = io.Fonts->Fonts[2]->CalcTextSizeA(io.Fonts->Fonts[2]->FontSize, FLT_MAX, 0, "Nyzen");
                    ImVec2 text_position = ImVec2(pos.x + (size.x - text_size.x) / 2, pos.y + 10); // Centering horizontally and adding some downward shift

                    draw->AddText(io.Fonts->Fonts[2], io.Fonts->Fonts[2]->FontSize, text_position, custom.get_accent_color(), "Nyzen");

                    PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));


                    ImGui::Text(E("Username"));
                    ImGui::InputText(E("##name"), username, IM_ARRAYSIZE(username));

                    ImGui::Text(E("Password"));
                    ImGui::InputText(E("##Password"), password, IM_ARRAYSIZE(password), ImGuiInputTextFlags_Password);


                    if (ImGui::Button(E("Login"), ImVec2(272, 27))) {
                        auth = 2;
                    }



                    SetCursorPos(ImVec2(0, 56));
                } ImGui::End();


            }
            if (loaded) {

                if (auth == 3) {

                    //ImGuiIO& io = ImGui::GetIO();

                    //auto windows_x = io.DisplaySize.x / 2;
                    //auto windows_y = io.DisplaySize.y / 2;

                    //auto myWindowX = windows_x - 250 / 2;
                    //auto myWindowY = windows_y - 250 / 2;

                    //ImGui::SetNextWindowPos(ImVec2(myWindowX, myWindowY));
                    //ImGui::SetNextWindowSize(ImVec2(250, 250));

                    if (ImGui::Begin("##Offline", nullptr, ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize)) {

                        ImGui::Text(" Sync is currently offline.");

                        if (ImGui::Button(E("Exit"), ImVec2(165, 27))) {

                            exit(0);
                        }
                    }
                    ImGui::End();
                }

                if (auth == 4) {

                    ImGuiIO& io = ImGui::GetIO();

                    auto windows_x = io.DisplaySize.x / 2;
                    auto windows_y = io.DisplaySize.y / 2;

                    auto myWindowX = windows_x - 250 / 2;
                    auto myWindowY = windows_y - 250 / 2;

                    ImGui::SetNextWindowPos(ImVec2(myWindowX, myWindowY));
                    ImGui::SetNextWindowSize(ImVec2(250, 250));

                    if (ImGui::Begin("##BlackLISTED", nullptr, ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize)) {

                        ImGui::Text("You are blacklisted from Sync");
                        if (ImGui::Button(E("Exit"), ImVec2(165, 27))) {

                            abort();
                            exit(0);
                        }

                    }
                    ImGui::End();
                }
            }



            /*
GENERATED CODE | READ-ONLY
You can directly copy from here, or from File > Export to clipboard
*/

            //static bool window = true;
            //ImGui::SetNextWindowSize(ImVec2(366, 282));
            ////!! You might want to use these ^^ values in the OS window instead, and add the ImGuiWindowFlags_NoTitleBar flag in the ImGui window !!

            //if (ImGui::Begin("window_name", &window))
            //{

            //    ImGui::SetCursorPos(ImVec2(-32, 41));
            //    ImGui::BeginChild(1, ImVec2(393, 233), true);

            //    ImGui::EndChild();

            //    ImGui::SetCursorPos(ImVec2(100, 100));
            //    ImGui::Text("change me");

            //}
            //ImGui::End();


            ///*
            //Reminder: some widgets may have the same label "##" (if you didn't change it), and can lead to undesired ID collisions.
            //More info: https://github.com/ocornut/imgui/blob/master/docs/FAQ.md#q-about-the-id-stack-system
            //*/




            if (auth == 2) {

                if (draw_menu) {
                    /*  setup_circles( );
                      draw_circles_and_lines(ImColor(255, 255, 255));*/


                    ImGuiIO& io = ImGui::GetIO(); (void)io;
                    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
                    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

                    static bool bools[50];
                    static int  ints[50];
                    vector < const char* > items = { "Variant", "Variant 1", "Variant 2", "Variant 3" };
                    static char buf[64];

                    static float color[4] = { 1.f, 1.f, 1.f, 1.f };

                    PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));

                    ImGui::Begin("Nyzen", NULL, ImGuiWindowFlags_NoDecoration); {

                        auto window = GetCurrentWindow();
                        auto draw = window->DrawList;
                        auto pos = window->Pos;
                        auto size = window->Size;

                        SetWindowSize(custom.window_size);

                        FX(draw, size, 0.20f);

                        custom.m_anim = ImLerp(custom.m_anim, 1.f, 0.04f);

                        draw->AddRectFilled(pos, pos + ImVec2(size.x, 55), ImColor(18, 18, 18), GetStyle().WindowRounding, ImDrawFlags_RoundCornersTop);
                        draw->AddLine(pos + ImVec2(0, 55), pos + ImVec2(size.x, 55), ImColor(1.f, 1.f, 1.f, 0.05f));

                        draw->AddText(io.Fonts->Fonts[2], io.Fonts->Fonts[2]->FontSize, pos + ImVec2(150 / 2 - io.Fonts->Fonts[2]->CalcTextSizeA(io.Fonts->Fonts[2]->FontSize, FLT_MAX, 0, "Nyzen").x / 2, 55 / 2 - io.Fonts->Fonts[2]->CalcTextSizeA(io.Fonts->Fonts[2]->FontSize, FLT_MAX, 0, "Nyzen").y / 2), custom.get_accent_color(), "Nyzen");

                        draw->AddRectFilled(pos + ImVec2(0, 56), pos + ImVec2(150, size.y), ImColor(18, 18, 18), GetStyle().WindowRounding, ImDrawFlags_RoundCornersBottomLeft);
                        draw->AddLine(pos + ImVec2(150, 56), pos + ImVec2(150, size.y), ImColor(1.f, 1.f, 1.f, 0.05f));

                        PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));

                        SetCursorPos(ImVec2(0, 56));
                        BeginGroup();

                        for (int i = 0; i < custom.m_tab_list.size(); ++i)
                            if (custom.tab(custom.m_tab_list.at(i), custom.m_tab == i))
                                custom.m_tab = i, custom.m_anim = 0.f;


                        //ImGui::SameLine();
                        //ImGui::SetCursorPosX(30);
                        //ImGui::Text("By Yusei.cc [1337]");
                        //ImGui::SetCursorPosX(300);
                        //ImGui::SetCursorPosY(25);
                        ///*ImGui::TextColored(ImVec4(0.0f, 0.56f, 0.7f, 1.0f), "TILL 10/20");*/
                        //ImGui::Separator();

                        EndGroup();

                        PopStyleVar();

                        switch (custom.m_tab) {
                             
                        case -1:

                            static auto timer = GetTickCount64();
                            if (GetTickCount64() - timer > 2000)
                                custom.m_tab = 0;

                            draw->AddRectFilled(pos, pos + size, GetColorU32(ImGuiCol_WindowBg), GetStyle().WindowRounding);

                            SetCursorPos(ImVec2(size.x / 2 - 16 / 2, size.y / 2 - 16 / 2));
                            custom.spinner("spinner", 16, 16, 7, 3.5, custom.get_accent_color(), ImColor(15, 15, 15), 6, 1);
                            ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 255, 255, 255));
                            
                            

                            break;
         


                        case 0:



                            PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));

                            SetCursorPos(ImVec2(150, 0));
                            BeginChild("##combat_subtab", ImVec2(size.x - 150, 55));

                            for (int i = 0; i < custom.m_combat_subtab_list.size(); ++i) {

                                if (custom.subtab(custom.m_combat_subtab_list.at(i), custom.m_combat_subtab == i, custom.m_combat_subtab_list.size()))
                                    custom.m_combat_subtab = i, custom.m_anim = 0.f;

                                if (i != custom.m_combat_subtab_list.size())
                                    SameLine();
                            }

                            EndChild();

                            PopStyleVar();

                            PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(8, 8));

                            SetCursorPos(ImVec2(180 - (20 * custom.m_anim), 65));
                            BeginChild("##aimbot_childs", ImVec2(size.x - 170, size.y - 75));

                            switch (custom.m_combat_subtab) {

                            case 0:

                                custom.group_box("Aimbot", ImVec2(GetWindowWidth() / 2 - GetStyle().ItemSpacing.x / 2, GetWindowHeight())); {

                                    Checkbox(E("Enable"), &settings::aimbot::enabled);

                                    Hotkey("Aim Key", &settings::aimbot::hotkey);

                               //     Checkbox(E("Triggerbot"), &settings::aimbot::TriggerBot);

                                    Checkbox(E("Lockon Npcs"), &settings::aimbot::ignore_peds);

                                    Checkbox(E("Show Field Of View"), &settings::visuals::draw_fov);
                            

                                        ImGui::SameLine();
                                        ImGui::ColorEdit4((E("##colorfov")), settings::tempcolor::fov_color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoBorder);
                                        settings::visuals::fov_color.Value.x = settings::tempcolor::fov_color[0];
                                        settings::visuals::fov_color.Value.y = settings::tempcolor::fov_color[1];
                                        settings::visuals::fov_color.Value.z = settings::tempcolor::fov_color[2];
                                        settings::visuals::fov_color.Value.w = settings::tempcolor::fov_color[3];

                                        Checkbox(E("Draw Filled FOV"), &settings::visuals::filled_fov);
                                    


                                } custom.end_group_box();

                                SameLine();

                                custom.group_box("Aimbot Customization", ImVec2(GetWindowWidth() / 2 - GetStyle().ItemSpacing.x / 2, GetWindowHeight())); {


                                    SliderInt("Aimbot Smoothing", &settings::aimbot::aimbot_smooth, 0, 200);
                                    SliderInt("Fov View", &settings::aimbot::aimbot_fov1, 0, 100);
                                    SliderInt("Aim Distance", &settings::aimbot::aimbot_distance, 0, 1000);
                                    Combo("Aim Bone", &settings::aimbot::aimbot_bone, settings::aimbot::aimbot_bones_list, IM_ARRAYSIZE(settings::aimbot::aimbot_bones_list));


                                } custom.end_group_box();


                                break;



                            case 1:


                                custom.group_box("Weapon##subtab1", ImVec2(GetWindowWidth() / 2 - GetStyle().ItemSpacing.x / 2, GetWindowHeight())); {

                                   
                                    Checkbox(E("No Recoil"), &settings::weapon::no_recoil);
                                    Checkbox(E("No Reload"), &settings::weapon::no_reload);
                                    Checkbox(E("No Spread"), &settings::weapon::no_spread);
                                    Checkbox(E("Unlimited Range"), &settings::weapon::infinite_range);
                                    Checkbox(E("Infite Ammo"), &settings::weapon::infite_ammo);
                                    Checkbox(E("Change Ammo"), &settings::attachments::explosiveammo);

                                    if (settings::attachments::explosiveammo) {
                                        ImGui::Combo("Explo Type", &settings::weapon::ExploType, settings::weapon::Explosionlist, IM_ARRAYSIZE(settings::weapon::Explosionlist));
                                    }
                                    Checkbox(E("Damage Boost"), &settings::weapon::damage_boost);
                                    Checkbox(E("Bullets per shot"), &settings::weapon::Bulletpershot);
                                } custom.end_group_box();


                                SameLine(), SetCursorPosY(0);

                                custom.group_box("Weapon Modify##subtab1", ImVec2(GetWindowWidth() / 2 - GetStyle().ItemSpacing.x / 2, GetWindowHeight())); {



                                        SliderFloat(E("Recoil"), &settings::weapon::recoil_value, 0.0, 5.0);
                                        SliderInt(E("Damage"), &settings::weapon::int_damage, 0, 1000);
                                        SliderInt(E("Bullets per shot"), &settings::weapon::Bulletpershot_value, 0, 50);

                              

                               



                                } custom.end_group_box();


                            

                                break;
                            }

                            EndChild();

                            PopStyleVar();

                            break;

                           case 1:

                            PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));

                            SetCursorPos(ImVec2(150, 0));
                            BeginChild("##visual_subtab", ImVec2(size.x - 150, 55));

                            for (int i = 0; i < custom.m_visual_subtab_list.size(); ++i) {

                                if (custom.subtab(custom.m_visual_subtab_list.at(i), custom.m_visual_subtab == i, custom.m_visual_subtab_list.size()))
                                    custom.m_visual_subtab = i, custom.m_anim = 0.f;

                                if (i != custom.m_visual_subtab_list.size())
                                    SameLine();
                            }

                            EndChild();

                            PopStyleVar();

                            PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(8, 8));

                            SetCursorPos(ImVec2(180 - (20 * custom.m_anim), 65));
                            BeginChild("##visual_childs", ImVec2(size.x - 170, size.y - 75));

                            switch (custom.m_visual_subtab) {

                            case 0:

                                custom.group_box("Esp", ImVec2(GetWindowWidth() / 2 - GetStyle().ItemSpacing.x / 2, GetWindowHeight())); {

                                    
                                    ImGui::SameLine(0, 20);
                                    
                                    {
                                        
                                        ::BeginGroup();
                                        {
                                             Checkbox(E("Enabled"), &settings::visuals::enabled);

                                             Checkbox(E("Health Bar"), &settings::visuals::healthbar);

                                             Checkbox(E("Armor Bar"), &settings::visuals::armorbar);

                                             Checkbox(E("Box"), &settings::visuals::box);

                                             Checkbox(E("Filled Box"), &settings::visuals::filled);

                                             Checkbox(E("Corner Box"), &settings::visuals::corner);

                                             Checkbox(E("Skeleton"), &settings::visuals::skeleton);

                                             Checkbox(E("Player Name"), &settings::visuals::playername);

                                             Checkbox(E("Weapon Name"), &settings::visuals::weapon_name);

                                             Checkbox(E("Snapline"), &settings::visuals::snapline);

                                             Checkbox(E("Distance"), &settings::visuals::dont_draw_distance);

                                             Checkbox(E("Draw Npcs"), &settings::visuals::draw_ped);

                                             Checkbox(E("Draw dead"), &settings::visuals::draw_dead);

                                       //      Checkbox(E("Draw Self"), &settings::visuals::Draw_LocalPlayer);

                                             Checkbox(E("Radar"), &settings::radar::enable2DRadar);

                                             /*if (settings::visuals::box)
                                             {
                                                 ImGui::SameLine();
                                                 ImGui::ColorEdit4(E(""), settings::tempcolor::box, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoBorder | ImGuiColorEditFlags_NoTooltip);
                                             }
                                             settings::visuals::boxcolor.Value.x = settings::tempcolor::box[0];
                                             settings::visuals::boxcolor.Value.y = settings::tempcolor::box[1];
                                             settings::visuals::boxcolor.Value.z = settings::tempcolor::box[2];
                                             settings::visuals::boxcolor.Value.w = settings::tempcolor::box[3];

                                             ImGui::Checkbox(E("skeleton"), &settings::visuals::skeleton);
                                             if (settings::visuals::skeleton)
                                             {
                                                 ImGui::SameLine();
                                                 ImGui::ColorEdit4(E(""), settings::tempcolor::skeleton, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoBorder | ImGuiColorEditFlags_NoTooltip);;
                                             }
                                             settings::visuals::CornerColor.Value.x = settings::tempcolor::skeleton[0];
                                             settings::visuals::CornerColor.Value.y = settings::tempcolor::skeleton[1];
                                             settings::visuals::CornerColor.Value.z = settings::tempcolor::skeleton[2];
                                             settings::visuals::CornerColor.Value.w = settings::tempcolor::skeleton[3];


                                             

                                             if (settings::visuals::box || settings::visuals::filled)
                                             {
                                                 
                                                 ImGui::Checkbox(E("Filled Box"), &settings::visuals::filled);

                                             }

                                             ImGui::Checkbox(E("Player Name"), &settings::visuals::playername);
                                             if (settings::visuals::playername)
                                             {
                                                 ImGui::SameLine();
                                                 ImGui::ColorEdit4(E(""), settings::tempcolor::name, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoBorder | ImGuiColorEditFlags_NoTooltip);
                                             }
                                             settings::visuals::namecolor.Value.x = settings::tempcolor::name[0];
                                             settings::visuals::namecolor.Value.y = settings::tempcolor::name[1];
                                             settings::visuals::namecolor.Value.z = settings::tempcolor::name[2];
                                             settings::visuals::namecolor.Value.w = settings::tempcolor::name[3];

                                             ImGui::Checkbox(E("weapon Name"), &settings::visuals::weapon_name);
                                             if (settings::visuals::weapon_name)
                                             {
                                                 ImGui::SameLine();
                                                 ImGui::ColorEdit4(E(""), settings::tempcolor::name, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoBorder | ImGuiColorEditFlags_NoTooltip);
                                             }
                                             settings::visuals::weapon_color.Value.x = settings::tempcolor::weapon[0];
                                             settings::visuals::weapon_color.Value.y = settings::tempcolor::weapon[1];
                                             settings::visuals::weapon_color.Value.z = settings::tempcolor::weapon[2];
                                             settings::visuals::weapon_color.Value.w = settings::tempcolor::weapon[3];

                                             ImGui::Checkbox(E("Snapline"), &settings::visuals::snapline);
                                             if (settings::visuals::snapline)
                                             {
                                                 ImGui::SameLine();
                                                 ImGui::ColorEdit4(E(""), settings::tempcolor::snapline, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoBorder | ImGuiColorEditFlags_NoTooltip);
                                             }
                                             settings::visuals::snapeline_color.Value.x = settings::tempcolor::snapline[0];
                                             settings::visuals::snapeline_color.Value.y = settings::tempcolor::snapline[1];
                                             settings::visuals::snapeline_color.Value.z = settings::tempcolor::snapline[2];
                                             settings::visuals::snapeline_color.Value.w = settings::tempcolor::snapline[3];

                                             ImGui::Checkbox(E("Distance"), &settings::visuals::dont_draw_distance);
                                             if (settings::visuals::dont_draw_distance)
                                             {
                                                 ImGui::SameLine();
                                                 ImGui::ColorEdit4(E(""), settings::tempcolor::distance, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoBorder | ImGuiColorEditFlags_NoTooltip);
                                             }
                                             settings::visuals::distance_color.Value.x = settings::tempcolor::distance[0];
                                             settings::visuals::distance_color.Value.y = settings::tempcolor::distance[1];
                                             settings::visuals::distance_color.Value.z = settings::tempcolor::distance[2];
                                             settings::visuals::distance_color.Value.w = settings::tempcolor::distance[3];
   
                                             ImGui::Checkbox(E("Corner Box"), &settings::visuals::corner);
                                             if (settings::visuals::corner)
                                             {
                                                 ImGui::SameLine();
                                                 ImGui::ColorEdit4(E(""), settings::tempcolor::corner, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoBorder | ImGuiColorEditFlags_NoTooltip);
                                             }
                                             settings::visuals::cornercolor.Value.x = settings::tempcolor::corner[0];
                                             settings::visuals::cornercolor.Value.y = settings::tempcolor::corner[1];
                                             settings::visuals::cornercolor.Value.z = settings::tempcolor::corner[2];
                                             settings::visuals::cornercolor.Value.w = settings::tempcolor::corner[3];*/

                                             

                                             ImGui::Checkbox(E("Hitsound"), &settings::visuals::hitsound);
                                             if (settings::visuals::hitsound) {
                                                 ImGui::InputText("##Hitsound Path", settings::visuals::hitsound_path, IM_ARRAYSIZE(settings::visuals::hitsound_path));
                                             }
                                             

                                             


                                        
                                        } custom.end_group_box();


                                    }
                                    
                                    
                                    
                                    
                       
                                        
                                      

                            

                                

                                     case 2:

                                

                                SameLine(), SetCursorPosY(0);

                                  custom.group_box("Esp Settings", ImVec2(GetWindowWidth() / 2 - GetStyle().ItemSpacing.x / 2, GetWindowHeight())); {

                                    ImGui::Text("Box Color");
                                    ImGui::SameLine();
                                    ImGui::ColorEdit4((E("##box")), settings::tempcolor::box, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoBorder);
                                    settings::visuals::boxcolor.Value.x = settings::tempcolor::box[0];
                                    settings::visuals::boxcolor.Value.y = settings::tempcolor::box[1];
                                    settings::visuals::boxcolor.Value.z = settings::tempcolor::box[2];
                                    settings::visuals::boxcolor.Value.w = settings::tempcolor::box[3];
                                    ImGui::Text("Corner Box Color");
                                    ImGui::SameLine();
                                    ImGui::ColorEdit4((E("##corner")), settings::tempcolor::corner, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoBorder);
                                    settings::visuals::cornercolor.Value.x = settings::tempcolor::corner[0];
                                    settings::visuals::cornercolor.Value.y = settings::tempcolor::corner[1];
                                    settings::visuals::cornercolor.Value.z = settings::tempcolor::corner[2];
                                    settings::visuals::cornercolor.Value.w = settings::tempcolor::corner[3];
                                    ImGui::Text("Skeleton Color");
                                    ImGui::SameLine();
                                    ImGui::ColorEdit4((E("##skssss")), settings::tempcolor::skeleton, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoBorder);
                                    settings::visuals::skeleton_color.Value.x = settings::tempcolor::skeleton[0];
                                    settings::visuals::skeleton_color.Value.y = settings::tempcolor::skeleton[1];
                                    settings::visuals::skeleton_color.Value.z = settings::tempcolor::skeleton[2];
                                    settings::visuals::skeleton_color.Value.w = settings::tempcolor::skeleton[3];
                                    ImGui::Text("Distance Color");
                                    ImGui::SameLine();
                                    ImGui::ColorEdit4((E("##distance")), settings::tempcolor::distance, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoBorder);
                                    settings::visuals::distance_color.Value.x = settings::tempcolor::distance[0];
                                    settings::visuals::distance_color.Value.y = settings::tempcolor::distance[1];
                                    settings::visuals::distance_color.Value.z = settings::tempcolor::distance[2];
                                    settings::visuals::distance_color.Value.w = settings::tempcolor::distance[3];
                                    ImGui::Text("Weapon Name Color");
                                    ImGui::SameLine();
                                    ImGui::ColorEdit4((E("##Weapon")), settings::tempcolor::weapon, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoBorder);
                                    settings::visuals::namecolor.Value.x = settings::tempcolor::weapon[0];
                                    settings::visuals::namecolor.Value.y = settings::tempcolor::weapon[1];
                                    settings::visuals::namecolor.Value.z = settings::tempcolor::weapon[2];
                                    settings::visuals::namecolor.Value.w = settings::tempcolor::weapon[3];
                                    /*ImGui::Text("Draw dead Color");
                                    ImGui::SameLine();
                                    ImGui::ColorEdit4((E("##Dead")), settings::tempcolor::draw, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoBorder);
                                    settings::visuals::namecolor.Value.x = settings::tempcolor::healthbar[0];
                                    settings::visuals::namecolor.Value.y = settings::tempcolor::healthbar[1];
                                    settings::visuals::namecolor.Value.z = settings::tempcolor::healthbar[2];
                                    settings::visuals::namecolor.Value.w = settings::tempcolor::healthbar[3];
                                    ImGui::Text("Armor Bar Color");
                                    ImGui::SameLine();
                                    ImGui::ColorEdit4((E("##Armor")), settings::tempcolor::armorbar, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoBorder);
                                    settings::visuals::namecolor.Value.x = settings::tempcolor::armorbar[0];
                                    settings::visuals::namecolor.Value.y = settings::tempcolor::armorbar[1];
                                    settings::visuals::namecolor.Value.z = settings::tempcolor::armorbar[2];
                                    settings::visuals::namecolor.Value.w = settings::tempcolor::armorbar[3];*/
                                    ImGui::Text("Player Name Color");
                                    ImGui::SameLine();
                                    ImGui::ColorEdit4((E("##name")), settings::tempcolor::name, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoBorder);
                                    settings::visuals::namecolor.Value.x = settings::tempcolor::name[0];
                                    settings::visuals::namecolor.Value.y = settings::tempcolor::name[1];
                                    settings::visuals::namecolor.Value.z = settings::tempcolor::name[2];
                                    settings::visuals::namecolor.Value.w = settings::tempcolor::name[3];
                                    ImGui::Text("Snap Line Color");
                                    ImGui::SameLine();
                                    ImGui::ColorEdit4((E("##snapline")), settings::tempcolor::snapline, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoBorder);
                                    settings::visuals::snapeline_color.Value.x = settings::tempcolor::snapline[0];
                                    settings::visuals::snapeline_color.Value.y = settings::tempcolor::snapline[1];
                                    settings::visuals::snapeline_color.Value.z = settings::tempcolor::snapline[2];
                                    settings::visuals::snapeline_color.Value.w = settings::tempcolor::snapline[3];
                                    ImGui::Spacing();
                                   
                                    

                                    ImGui::SliderInt(E("Render Distance"), &settings::visuals::render_distance, 0, 1000);
                                    ImGui::SliderInt(E("FillBox Alpha"), &settings::visuals::FillBoxAlpha, 1, 255, nullptr, ImGuiSliderFlags_AlwaysClamp || ImGuiSliderFlags_NoInput);
                                    ImGui::Text("Health & Armor Bar positions");
                                    static const char* Healthbar[4] = { "Side", "Bottom", "Top", "Left"};
                                    ImGui::Combo("##Style", &settings::visuals::healthbar_style, Healthbar, 3);

                                
                                
                                  } custom.end_group_box();

                                  break;


                            }

                            EndChild();

                            PopStyleVar();

                            break;

                               




                              case 1:

                              custom.group_box("Vehicle Visuals##subtab1", ImVec2(GetWindowWidth() / 2 - GetStyle().ItemSpacing.x / 2, GetWindowHeight())); {


                                   /*ImGui::SameLine(0, 20);*/

                                  /*ImGui::Text("Will Be Avaible In The Next Update");*/

                                 /* Checkbox(E("Enabled"), &settings::vehicle::enabled)*/;

                                 /* Checkbox(E("Vehicle Esp"), &settings::vehicle::vehicle_esp);*/


                                  Checkbox(E("Enabled"), &settings::vehicle::vehicle_esp);

                                  Checkbox(E("Vehicle Name"), &settings::vehicle::vehicle_name);

                                  Checkbox(E("Vehicle Distance"), &settings::vehicle::vehicle_distance);

                                  Checkbox(E("Vehicle Color"), &settings::vehicle::vehicleprimcolor);

                                  Checkbox(E("Vehicle Health"), &settings::vehicle::vehicle_health);

                                  Checkbox(E("Vehicle Snap Line"), &settings::vehicle::vehicle_snapline);


                              } custom.end_group_box();


                          }


                          

                           SameLine(), SetCursorPosY(0);

                         /*  ImGui::SameLine(0, 20);*/

                          
                          

                           custom.group_box("Object Visuals", ImVec2(GetWindowWidth() / 2 - GetStyle().ItemSpacing.x / 2, GetWindowHeight())); {



                               Checkbox(E("Enabled"), &settings::object::object_esp);

                               Checkbox(E("Object Name"), &settings::object::object_name);

                               Checkbox(E("Object Distance"), &settings::object::object_distance);

                               Checkbox(E("Object Color"), &settings::object::object_snapline);

                               Checkbox(E("Object Health"), &settings::object::object_marker);


                               break;


                            }

                            EndChild();

                            PopStyleVar();

                            break;








                        case 2:
                            PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));

                            SetCursorPos(ImVec2(150, 0));
                            BeginChild("##self_subtab", ImVec2(size.x - 150, 55));

                            for (int i = 0; i < custom.m_self_subtab_list.size(); ++i) {

                                if (custom.subtab(custom.m_self_subtab_list.at(i), custom.m_self_subtab == i, custom.m_self_subtab_list.size()))
                                    custom.m_self_subtab = i, custom.m_anim = 0.f;

                                if (i != custom.m_self_subtab_list.size())
                                    SameLine();
                            }

                            EndChild();

                            PopStyleVar();

                            PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(8, 8));

                            SetCursorPos(ImVec2(180 - (20 * custom.m_anim), 65));
                            BeginChild("##self_childs", ImVec2(size.x - 170, size.y - 75));

                            switch (custom.m_self_subtab) {

                            case 0:

                                custom.group_box("Local Player", ImVec2(GetWindowWidth() / 2 - GetStyle().ItemSpacing.x / 2, GetWindowHeight())); {

                                    Checkbox("Godmode", &settings::self::godmode);
                                    if (IsItemHovered())
                                        SetTooltip("Sometimes This Option Will Be Get Detected By Half Decent Anticheats");
                                    //ImGui::TextColored(ImVec4(148.0f, 71.0f, 0.0f, 1.0f), "(!)"); // Symbol in Rot neben der Checkbox

                                    ImGui::Checkbox("Semi-GodMode", &settings::self::semigodmode);

                                    Checkbox(E("Noclip"), &settings::self::noclip);

                                    Checkbox(E("No Ragdoll"), &settings::self::NoRagdoll);

                                    ImGui::Checkbox("Fastrun", &settings::self::fastrun);

                                    ImGui::Checkbox("Bug Player", &settings::self::Bugplayer);

                                    ImGui::Checkbox("Fly High", &settings::self::flyhigh);

                                    Checkbox(E("No Collistion"), &settings::self::nocol);
                                    if (IsItemHovered())
                                        SetTooltip("You Will be Able To Walk trough Walls.");
                                    Checkbox(E("Super Jump"), &settings::self::super_jump_enabled);
                                    if (IsItemHovered())
                                        SetTooltip("You Will Jump like Superman");


                                    Checkbox(E("Infinite Armor"), &settings::self::Infinite_Armor);

                                    Checkbox(E("Invisible"), &settings::self::invisible);
                                    if (IsItemHovered())
                                      SetTooltip("Only Clientside");

                                    if (Button("Suicide", ImVec2(GetWindowWidth() - 24, 25))) {

                                        settings::self::suicide = true;
                                        notifications.add("Killed Localplayer !");
                                    }



                                

                                   

                                } custom.end_group_box();

 

                                SameLine(), SetCursorPosY(0);

                                custom.group_box("Other", ImVec2(GetWindowWidth() / 2 - GetStyle().ItemSpacing.x / 2, GetWindowHeight())); {

                                   
                                    ImGui::Hotkey(E("Noclip Key :   "), &settings::self::hotkey_noclip);

                                    ImGui::SliderFloat((E("Noclip Speed")), &settings::self::noclipspeedlol, 1.0, 5.0, nullptr, ImGuiSliderFlags_AlwaysClamp || ImGuiSliderFlags_NoInput);
                            
                                    ImGui::SliderFloat((E("Run Speed")), &settings::self::RunSpeedToSet, 1.0, 5.0, nullptr, ImGuiSliderFlags_AlwaysClamp || ImGuiSliderFlags_NoInput);

                                    ImGui::PopStyleColor();

                                    ImGui::SliderInt(E("Health"), &settings::self::health, 0, 100);

                                    ImGui::SliderInt(E("Armor"), &settings::self::armor, 0, 100);

                                    ImGui::SliderInt(E("Fov"), &settings::self::FovValue, 5, 130);

                                    ImGui::Hotkey(E("Hotkey Health :   "), &settings::self::HotkeyHealth);

                                    ImGui::Hotkey(E("Hotkey Armor :   "), &settings::self::HotkeyArmor);

                                    ImGui::Spacing();








                                    if (Button("Set Armor", ImVec2(GetWindowWidth() - 24, 25))) {
                                        notifications.add(" :)");
                                        settings::self::set_armor = true;
                                    }


                                    if (Button("Set Health", ImVec2(GetWindowWidth() - 24, 25))) {
                                        notifications.add(" :)");
                                        settings::self::set_health = true;
                                    }

                                    if (Button("FOV Changer", ImVec2(GetWindowWidth() - 24, 25))) {
                                        notifications.add(" Successfully Changed Fov!");
                                        settings::self::fovcganger = true;
                                    }







                                



                                } custom.end_group_box();

                                break;

                  
    case 1:
        custom.group_box("Teleporter", ImVec2(GetWindowWidth() / 2 - GetStyle().ItemSpacing.x / 2, GetWindowHeight())); {
            if (ImGui::BeginListBox(E("##List"), ImVec2(280, 600))) {
                for (int i = 0; i < Teleport::namedCoords.size(); i++) {
                    const Teleport::NamedCoordinates& namedCoord = Teleport::namedCoords[i];

                    // Filter by search string or show all if search string is empty
                    if (strstr(namedCoord.name.c_str(), settings::Teleport::searchString) != NULL || settings::Teleport::searchString[0] == '\0') {
                        bool isSelected = (settings::Teleport::Index == i);

                        if (ImGui::Selectable(namedCoord.name.c_str(), isSelected)) {
                            settings::Teleport::Index = i;
                        }

                        if (isSelected) {
                            ImGui::SetItemDefaultFocus();
                        }
                    }
                }
                ImGui::EndListBox();
            }
        } custom.end_group_box();

        ImGui::SameLine();

        custom.group_box("Teleport", ImVec2(GetWindowWidth() / 2 - GetStyle().ItemSpacing.x / 2, GetWindowHeight())); {
            if (ImGui::Button("Teleport To Marker", ImVec2(GetWindowWidth() - 24, 25))) {
                settings::self::tptowaypoint = true;
                notifications.add("Teleported !");
            }

            if (ImGui::Button("Teleport", ImVec2(GetWindowWidth() - 24, 25))) {
                int selectedIndex = settings::Teleport::Index;
                if (selectedIndex >= 0 && selectedIndex < Teleport::namedCoords.size()) {
                    const Teleport::NamedCoordinates& selectedCoord = Teleport::namedCoords[selectedIndex];

                    hk_World* World = reinterpret_cast<hk_World*>(*reinterpret_cast<uint64_t*>(FiveM::World));
                    if (World) {
                        hk_Ped* LocalPlayer = World->LocalPlayer();
                        if (LocalPlayer) {
                            hk_ObjectNavigationPed* Nav = LocalPlayer->ObjectNavigation();
                            if (Nav) {
                                // Set the player's coordinates to the selected location
                                LocalPlayer->SetCoordinate(Vector3(selectedCoord.x, selectedCoord.y, selectedCoord.z));
                                Nav->SetCoordinate(Vector3(selectedCoord.x, selectedCoord.y, selectedCoord.z));
                                notifications.add("Teleported to " + selectedCoord.name + "!");
                            }
                            else {
                                notifications.add("Failed to teleport: Navigation not available!");
                            }
                        }
                        else {
                            notifications.add("Failed to teleport: Local player not available!");
                        }
                    }
                    else {
                        notifications.add("Failed to teleport: World not available!");
                    }
                }
                else {
                    notifications.add("Failed to teleport: Invalid index selected!");
                }
            }
        }
        } custom.end_group_box();

        break;



                        case 3:
                            PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));

                            SetCursorPos(ImVec2(150, 0));
                            BeginChild("##vehicle_subtab", ImVec2(size.x - 150, 55));

                            for (int i = 0; i < custom.m_vehicle_subtab_list.size(); ++i) {

                                if (custom.subtab(custom.m_vehicle_subtab_list.at(i), custom.m_vehicle_subtab == i, custom.m_vehicle_subtab_list.size()))
                                    custom.m_vehicle_subtab = i, custom.m_anim = 0.f;

                                if (i != custom.m_vehicle_subtab_list.size())
                                    SameLine();
                            }

                            EndChild();

                            PopStyleVar();

                            PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(8, 8));

                            SetCursorPos(ImVec2(180 - (20 * custom.m_anim), 65));
                            BeginChild("##vehicle_childs", ImVec2(size.x - 170, size.y - 75));

                            switch (custom.m_vehicle_subtab) {

                            

                            case 0:
                                custom.group_box("Vehicle Modification##subtab1", ImVec2(GetWindowWidth() / 2 - GetStyle().ItemSpacing.x / 2, GetWindowHeight())); {

                                    Checkbox(E("Godmode"), &settings::vehicle::vehicle_godmode_bool);

                                    Checkbox(E("Vehicle Speed"), &settings::vehicle::vehicle_speed_bool);

                                    Checkbox(E("Brake Force"), &settings::vehicle::Instantbrake);

                                    Checkbox(E("Easy Handling"), &settings::vehicle::easy_handling);

                                    Checkbox(E("Shift Boost"), &settings::vehicle::shift_boost);

                                    Checkbox(E("Change Gravity"), &settings::vehicle::vehicle_gravity_bool);

                                    Checkbox(E("Invisible"), &settings::vehicle::Vecinvisible);
                                    if (IsItemHovered())
                                        SetTooltip("Only Clientside");

                                    if (Button("Repair Vehicle", ImVec2(GetWindowWidth() - 24, 25))) {

                                        settings::vehicle::vehicle_repair = true;
                                        notifications.add("Repaired !");
                                    }
                                    if (IsItemHovered())
                                        SetTooltip("Only Engine");

                                        if (Button("Destroy Vehicle", ImVec2(GetWindowWidth() - 24, 25))) {

                                            settings::vehicle::destroy = true;
                                            notifications.add("Repaired !");
                                        }
                                        if (IsItemHovered())
                                            SetTooltip("Only Engine");


                                } custom.end_group_box();

                                SameLine(), SetCursorPosY(0); 

                                custom.group_box("Vehicle Settings", ImVec2(GetWindowWidth() / 2 - GetStyle().ItemSpacing.x / 2, GetWindowHeight())); {

                                    ImGui::SliderInt(E("Vehicle Speed"), &settings::vehicle::vehicle_speed_value, 0, 1000);

                                    ImGui::SliderInt(E("Vehicle Brake Force"), &settings::vehicle::vehicle_brak_value, 0, 100);

                                    ImGui::SliderInt(E("Gravity Value"), &settings::vehicle::vehicle_gravity_value, 0, 100);





                                } custom.end_group_box();

                                break;


                                SameLine(), SetCursorPosY(0);

                            case 1:
                              
                                custom.group_box("Vehicle List", ImVec2(GetWindowWidth() / 2 - GetStyle().ItemSpacing.x / 2, GetWindowHeight())); {

                                    hk_World* World = (hk_World*)*(uint64_t*)(FiveM::World);
                                    if (!World)
                                        return;
                                    hk_Ped* LocalPlayer = World->LocalPlayer();
                                    if (!World)
                                        return;
                                    if (LocalPlayer) {

                                        hk_ObjectNavigationPed* Nav = LocalPlayer->ObjectNavigation();
                                        if (!Nav)
                                            return;

                                        hk_ReplayInterface* ReplayInterface = (hk_ReplayInterface*)*(uint64_t*)(FiveM::ReplayInterface);
                                        if (!ReplayInterface)
                                            return;

                                        hk_VehicleInterface* VehicleInterface = ReplayInterface->VehicleInterface();
                                        if (!VehicleInterface)
                                            return;

                                        if (ImGui::BeginListBox("", ImVec2(220, 300))) {
                                            for (int i = 0; i < VehicleInterface->VehicleMaximum(); i++) {

                                                hk_Vehicle* Vehicles = VehicleInterface->VehicleList()->Vehicle(i);
                                                if (!Vehicles)
                                                    continue;
                                                auto playerName = Vehicles->VehicleModelInfo()->GetCharName();
                                                const char* c = playerName;
                                                const char* items[] = { c };

                                                bool is_selected = (selectedVeh_index == i);
                                                if (ImGui::Selectable(playerName, is_selected)) {
                                                    selectedVeh_index = i;
                                                }
                                            }
                                            ImGui::EndListBox();
                                        }
                                    }
                                } custom.end_group_box();

                                ImGui::SameLine(), SetCursorPosY(0);

                                custom.group_box("Vehicle Options", ImVec2(GetWindowWidth() / 2 - GetStyle().ItemSpacing.x / 2, GetWindowHeight())); {

                                    hk_World* World = (hk_World*)*(uint64_t*)(FiveM::World);
                                    if (!World)
                                        return;
                                    hk_Ped* LocalPlayer = World->LocalPlayer();

                                    if (LocalPlayer) {

                                        hk_ObjectNavigationPed* Nav = LocalPlayer->ObjectNavigation();
                                        if (!Nav)
                                            return;

                                        hk_ReplayInterface* ReplayInterface = (hk_ReplayInterface*)*(uint64_t*)(FiveM::ReplayInterface);
                                        if (!ReplayInterface)
                                            return;

                                        hk_VehicleInterface* VehicleInterface = ReplayInterface->VehicleInterface();
                                        if (!VehicleInterface)
                                            return;

                                        hk_Vehicle* SelectedVehicle = VehicleInterface->VehicleList()->Vehicle(selectedVeh_index);

                                        if (SelectedVehicle->GetCoordinate().x != 0) {
                                            std::string healthtoshow = "Health : " + std::to_string(SelectedVehicle->GetHealth());
                                            ImGui::Text(healthtoshow.c_str());

                                            std::string coordstoshowx = "X : " + std::to_string(SelectedVehicle->GetCoordinate().x);
                                            std::string coordstoshowy = "Y : " + std::to_string(SelectedVehicle->GetCoordinate().y);
                                            std::string coordstoshowz = "Z : " + std::to_string(SelectedVehicle->GetCoordinate().z);
                                            ImGui::Text(coordstoshowx.c_str());
                                            ImGui::Text(coordstoshowy.c_str());
                                            ImGui::Text(coordstoshowz.c_str());
                                            if (ImGui::Button("Teleport To Vehicle")) {
                                                Nav->SetRotation({ 0, 0, 0, 0 });
                                                LocalPlayer->SetVelocity();
                                                LocalPlayer->SetCoordinate(SelectedVehicle->GetCoordinate());
                                                Nav->SetCoordinate(SelectedVehicle->GetCoordinate());
                                            }

                                            if (ImGui::Button("Repair Vehicle (Engine)")) {
                                                SelectedVehicle->SetEngineHealth(1000);
                                                notifications.add("Vehicle Engine Repaired!");
                                            }

                                            if (ImGui::Button("Destroy Vehicle")) {
                                                if (ImGui::Button("Repair Vehicle (Engine)")) {
                                                    SelectedVehicle->SetEngineHealth(0); // Repariere das Fahrzeug (Motor)
                                                    notifications.add("Vehicle Engine Destroyed!");
                                                }
                                            }
                                        }
                                    }
                                 }
                                } custom.end_group_box();

                                break;


                        case 4:
                            PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));

                            SetCursorPos(ImVec2(150, 0));
                            BeginChild("##globalplayer_subtab", ImVec2(size.x - 150, 55));

                            for (int i = 0; i < custom.m_player_subtab_list.size(); ++i) {

                                if (custom.subtab(custom.m_player_subtab_list.at(i), custom.m_player_subtab == i, custom.m_player_subtab_list.size()))
                                    custom.m_player_subtab = i, custom.m_anim = 0.f;

                                if (i != custom.m_player_subtab_list.size())
                                    SameLine();
                            }

                            EndChild();

                            PopStyleVar();

                            PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(8, 8));

                            SetCursorPos(ImVec2(180 - (20 * custom.m_anim), 65));
                            BeginChild("##Global Player_childs", ImVec2(size.x - 170, size.y - 75));

                            switch (custom.m_player_subtab) {

                            case 0:

                                custom.group_box("Player List", ImVec2(GetWindowWidth() / 2 - GetStyle().ItemSpacing.x / 2, GetWindowHeight())); {

                                    hk_World* World = (hk_World*)*(uint64_t*)(FiveM::World);
                                    if (!World)
                                        return;
                                    hk_Ped* LocalPlayer = World->LocalPlayer();
                                    if (!World)
                                        return;
                                    if (LocalPlayer) {

                                        hk_ObjectNavigationPed* Nav = LocalPlayer->ObjectNavigation();
                                        if (!Nav)
                                            return;

                                        hk_ReplayInterface* ReplayInterface = (hk_ReplayInterface*)*(uint64_t*)(FiveM::ReplayInterface);
                                        if (!ReplayInterface)
                                            return;

                                        hk_PedInterface* PedInterface = ReplayInterface->PedInterface();
                                        if (!PedInterface)
                                            return;

                                        if (ImGui::BeginListBox(" ", ImVec2(220, 300))) {
                                            for (int i = 0; i < PedInterface->PedMaximum(); i++) {

                                                hk_Ped* Peds = PedInterface->PedList()->Ped(i);
                                                if (!Peds)
                                                    continue;
                                                   int PlayerID = FiveM::pointer_to_handle((DWORD64)Peds);
                                                void* m_net_player_data = (void*)(Peds->PlayerInfo() + 0x20);
                                                bool IsPed = false;


                                                auto playerName = FiveM::getpname(m_net_player_data);
                                                const char* c = playerName;
                                                const char* items[] = { c };

                                                auto ped_type = Peds->GetPedType();
                                                if (!ped_type) {
                                                    continue;
                                                }
                                                ped_type = ped_type << 11 >> 25;

                                                if (ped_type != 2) {
                                                    IsPed = true;

                                                }

                                                if (IsPed)
                                                {
                                                    continue;
                                                }
                                                bool is_selected = (selected_index == i);
                                                if (ImGui::Selectable(playerName, is_selected)) {

                                                    selected_index = i;
                                                }
                                            }

                                            ImGui::EndListBox();
                                        }

                                        hk_Ped* SelectedPed = PedInterface->PedList()->Ped(selected_index);
                                    }


                                } custom.end_group_box();


                                SameLine(), SetCursorPosY(0);

                                custom.group_box("Player Options", ImVec2(GetWindowWidth() / 2 - GetStyle().ItemSpacing.x / 2, GetWindowHeight())); {

                                    hk_World* World = (hk_World*)*(uint64_t*)(FiveM::World);
                                    if (!World)
                                        return;
                                    hk_Ped* LocalPlayer = World->LocalPlayer();

                                    if (LocalPlayer) {

                                        hk_ObjectNavigationPed* Nav = LocalPlayer->ObjectNavigation();
                                        if (!Nav)
                                            return;

                                        hk_ReplayInterface* ReplayInterface = (hk_ReplayInterface*)*(uint64_t*)(FiveM::ReplayInterface);
                                        if (!ReplayInterface)
                                            return;

                                        hk_PedInterface* PedInterface = ReplayInterface->PedInterface();
                                        if (!PedInterface)
                                            return;

                                        hk_Ped* SelectedPed = PedInterface->PedList()->Ped(selected_index);

                                        if (SelectedPed->GetCoordinate().x != 0) {
                                            std::string healthtoshow = "Health : " + std::to_string(SelectedPed->GetHealth());
                                            std::string armortoshow = "Armor : " + std::to_string(SelectedPed->GetArmor());
                                            ImGui::Text(healthtoshow.c_str());
                                            ImGui::Text(armortoshow.c_str());

                                            std::string coordstoshowx = "X : " + std::to_string(SelectedPed->GetCoordinate().x);
                                            std::string coordstoshowy = "Y : " + std::to_string(SelectedPed->GetCoordinate().y);
                                            std::string coordstoshowz = "Z : " + std::to_string(SelectedPed->GetCoordinate().z);
                                            ImGui::Text(coordstoshowx.c_str());
                                            ImGui::Text(coordstoshowy.c_str());
                                            ImGui::Text(coordstoshowz.c_str());
                                            if (ImGui::Button("Teleport To Player")) {
                                                if (SelectedPed != LocalPlayer) {
                                                    Nav->SetRotation({ 0, 0, 0, 0 });
                                                    LocalPlayer->SetVelocity();
                                                    LocalPlayer->SetCoordinate(SelectedPed->GetCoordinate());
                                                    Nav->SetCoordinate(SelectedPed->GetCoordinate());
                                                }
                                            }



                                            void* m_net_player_data = (void*)(SelectedPed->PlayerInfo() + 0x20);
                                            auto it = std::find(FiveM::Friend.begin(), FiveM::Friend.end(), FiveM::getpname(m_net_player_data));
                                            if (it != FiveM::Friend.end()) {
                                                if (ImGui::Button("Remove Friend")) {
                                                    // auto it = std::find(FiveM::Friend.begin( ), FiveM::Friend.end( ), (DWORD64)SelectedPed);
                                                    int index = it - FiveM::Friend.begin();
                                                    FiveM::Friend.erase(FiveM::Friend.begin() + index);
                                                }
                                            }
                                            else {
                                                if (ImGui::Button("Add Friend")) {
                                                    FiveM::Friend.push_back(FiveM::getpname(m_net_player_data));
                                                }
                                            }
                                        }
                                    }

                                } custom.end_group_box();

                                break;

                            //case 1:

                            //    custom.group_box("Vehicle List", ImVec2(GetWindowWidth() / 2 - GetStyle().ItemSpacing.x / 2, GetWindowHeight())); {




                            //    } custom.end_group_box();

                            //    //custom.group_box("Group", ImVec2(GetWindowWidth() / 2 - GetStyle().ItemSpacing.x / 2, GetWindowHeight() / 2 - GetStyle().ItemSpacing.y / 2)); {

                            //    //    for (int i = 0; i < 50; ++i)
                            //    //        Text(std::to_string(i).c_str());

                            //    //} custom.end_group_box();

                            //    //custom.group_box("Vehicle Esp", ImVec2(GetWindowWidth() / 2 - GetStyle().ItemSpacing.x / 2, GetWindowHeight() / 2 - GetStyle().ItemSpacing.y / 2)); {



                            //    //} custom.end_group_box();

                            //    SameLine(), SetCursorPosY(0);

                            //    custom.group_box("Vehicle Options", ImVec2(GetWindowWidth() / 2 - GetStyle().ItemSpacing.x / 2, GetWindowHeight())); {

                            //    } custom.end_group_box();


                            }






                            EndChild();

                            PopStyleVar();

                            break;


                        case 5:
                            PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));

                            SetCursorPos(ImVec2(150, 0));
                            BeginChild("##misc_subtab", ImVec2(size.x - 150, 55));

                            for (int i = 0; i < custom.m_misc_subtab_list.size(); ++i) {

                                if (custom.subtab(custom.m_misc_subtab_list.at(i), custom.m_misc_subtab == i, custom.m_misc_subtab_list.size()))
                                    custom.m_misc_subtab = i, custom.m_anim = 0.f;

                                if (i != custom.m_misc_subtab_list.size())
                                    SameLine();
                            }

                            EndChild();

                            PopStyleVar();

                            PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(8, 8));

                            SetCursorPos(ImVec2(180 - (20 * custom.m_anim), 65));
                            BeginChild("##Misc_childs", ImVec2(size.x - 170, size.y - 75));

                            switch (custom.m_player_subtab) {

                            case 0:

                                custom.group_box("Settings", ImVec2(GetWindowWidth() / 2 - GetStyle().ItemSpacing.x / 2, GetWindowHeight())); {

                                    Checkbox(E("Watermark"), &settings::visuals::watermark);
                                    Checkbox(E("streamproof"), &settings::visuals::streamproof);
                                    Checkbox(E("Toggle Crosshair"), &settings::visuals::crosshair);

   
                                
                                    if (settings::visuals::crosshair) {

                                        ImGui::Combo(E("Crosshair Style"), &settings::visuals::crossahir_style, settings::visuals::sss, IM_ARRAYSIZE(settings::visuals::sss));
                                    }


                                    //if (settings::visuals::streamproof)

                                    //{
                                    //    SetWindowDisplayAffinity((HWND),(WDA_EXCLUDEFROMCAPTURE);
                                    //
                                    //}
                               
                             
                                    //else
                                    //{
                                    //    SetWindowDisplayAffinity((HWND),(WDA_NONE);
                                    //
                                    //}

                                    //if (settings::visuals::streamproof)
                                    //{
                                    //    SetWindowDisplayAffinity(HWND, WDA_EXCLUDEFROMCAPTURE);
                                    //}
                                    //else
                                    //{
                                    //    SetWindowDisplayAffinity(HWND, WDA_NONE);
                                    //}
                                
                                    ImGui::Checkbox("Rainbow", &settings::Menu::rainbowMode);


                                    ImGui::Hotkey("Menu Key:", &Menu::menu_key);
                                    Text("Menu Color");
                                    SameLine(GetWindowWidth() - 40);
                                    if (ColorEdit4("##accent", custom.accent_c, NO_ALPHA))
                                        StyleColorsDark();


                                    if (settings::thread::lock_menu_layout) {
                                        settings::thread::windows_flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize;


                                    }
                                    if (settings::Menu::rainbowMode)
                                    {
                                        float time = ImGui::GetTime();
                                        custom.accent_c[0] = sinf(0.6f * time + 0.0f) * 0.5f + 0.5f;
                                        custom.accent_c[1] = sinf(0.6f * time + 2.0f) * 0.5f + 0.5f;
                                        custom.accent_c[2] = sinf(0.6f * time + 4.0f) * 0.5f + 0.5f;
                                        custom.accent_c[3] = 1.0f; // Alpha-Kanal auf 1.0 setzen, falls benötigt
                                    }
                                    else {
                                       
                                        ImGui::StyleColorsDark();
                                    }

                                    Checkbox(E("Block Input"), &settings::self::blockinput);

                                    if (ImGui::Button("Crash Game ")) {
                                        exit(-1);
                                    }
                                    ImGui::SameLine();
                                    if (ImGui::Button("Unload")) {
                                        draw_menu = false;
                                    }

                                     } custom.end_group_box();

                                   SameLine();




                                    custom.group_box("Infos", ImVec2(GetWindowWidth() / 2 - GetStyle().ItemSpacing.x / 2, GetWindowHeight())); {


                                        ImGui::Text(E("Last Update:  08.05.2025"));

                                        /*ImGui::Text("Nigga384820");*/
                                        auto window = GetCurrentWindow();
                                        auto draw = window->DrawList;
                                        auto pos = window->Pos;
                                        auto size = window->Size;
                                        auto style = GetStyle();


                                        //draw->AddRectFilled(pos + ImVec2(0, size.y - 20), pos + size, ImColor(15, 14, 21),style .WindowRounding, ImDrawFlags_RoundCornersBottom);
                                        //draw->AddText(pos + ImVec2(5, size.y - 18), GetColorU32(ImGuiCol_Text), "Yusei.cc ");
                                        //draw->AddText(pos + ImVec2(size.x - CalcTextSize("By Stoned1337").x - 5, size.y - 18), GetColorU32(ImGuiCol_Text), "By Stoned1337");


                                } custom.end_group_box();

                                SameLine();

                                




                            } custom.end_group_box();


                            //break;

                            //

                            //SetCursorPos(ImVec2(150, 0));
                            //BeginChild("##m_lua_subtab", ImVec2(size.x - 150, 55));
                            // 
                            //ImGui::Checkbox(E("Lock menu layout"), &settings::thread::lock_menu_layout);



                            }    }


                    } ImGui::End();

                    PopStyleVar();
                    notifications.initialize();

                }
                else {

                    exit(3);
                }
            }
        }
    }

