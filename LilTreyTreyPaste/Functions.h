#pragma once
#include "terrydriver.h"
#include "utils.h"
#include "offsets.h"

int Health() {

    return Driver::Read<int>(variables::derefent + offsets::Health);
}
int Shield() {

    return Driver::Read<int>(variables::derefent + offsets::Shield);
}
uintptr_t EntName() {

    return Driver::Read<uintptr_t>(variables::derefent + offsets::EntName);
}

void GlowObjects() {

    Driver::Write<float>(variables::derefent + 0x2FC, FLT_MAX);
    Driver::Write<int>(variables::derefent + 0x350, TRUE);
    Driver::Write<float>(variables::derefent + 0x1D0, TerryFosterSettings::R);
    Driver::Write<float>(variables::derefent + 0x1D4, TerryFosterSettings::G);
    Driver::Write<float>(variables::derefent + 0x1D8, TerryFosterSettings::B);

    for (int offset = 0x2F0; offset <= 0x31C; offset += 0x4)
        Driver::Write<float>(variables::derefent + offset, FLT_MAX);

}

void EntityLoop() {

   while (true) {

        variables::LocalPlayer = Driver::Read<uintptr_t>(variables::ModuleBase + offsets::LocaPlayer); // scann for localplayer if not found continue 
        //printf("[+] LocalPlayer -> 0x%x\n", variables::LocalPlayer);
        if (variables::LocalPlayer > 0x7fffffff0000 || variables::LocalPlayer < 0xffffff || !variables::LocalPlayer) // Check EntList
            continue;

        variables::EntityList = (variables::ModuleBase + offsets::EntityList); // find EntList
        if (variables::EntityList > 0x7fffffff0000 || variables::EntityList < 0xffffff || !variables::EntityList) // Check EntList
            continue;

        //printf("[+] EntityList -> 0x%x\n", variables::EntityList);

        variables::BaseEntity = Driver::Read<uintptr_t>(variables::EntityList); // dereference EntityList
        if (variables::BaseEntity > 0x7fffffff0000 || variables::BaseEntity < 0xffffff || !variables::BaseEntity) // Check EntList
            continue;

        //printf("[+] BaseEntity -> 0x%x\n", variables::BaseEntity);

        if (variables::BaseEntity) {
            for (int i = 0; i < 61; i++) {
                variables::derefent = Driver::Read<uintptr_t>(variables::EntityList + ((uintptr_t)i << 5));
                variables::Entity_Handle = Driver::Read<uintptr_t>(variables::derefent); // Handle to entitys 
                //printf("[+] Dereferenced Entity -> 0x%x\n", variables::derefent);
                if (!variables::derefent)
                    continue;
                //std::cout << "[+] EntityName ->" << EntName() << std::endl;
                //std::cout << "[+] Health ->" << Health() << std::endl;
                //std::cout << "[+] Shield ->" << Shield() << std::endl;
                if (EntName() == 0x726579616C70) { //player in ascii (backwards due to endianess)
                    // Checkif entity is named 0x726579616C70 otherwise you would make the world object glow which results in crash 
                    if (Health() >= 85)
                    {
                        TerryFosterSettings::R = { 0 };
                        TerryFosterSettings::G = { 102 };
                        TerryFosterSettings::B = { 0 };

                    }
                    else if (Health() >= 40 && variables::Health <= 84)
                    {
                        TerryFosterSettings::R = { 0 };
                        TerryFosterSettings::G = { 40 };
                        TerryFosterSettings::B = { 40 };
                    }
                    else if (Health() <= 39)
                    {
                        TerryFosterSettings::R = { 80 };
                        TerryFosterSettings::G = { 0 };
                        TerryFosterSettings::B = { 0 };
                    }


                        GlowObjects();
                        // call all functions here
                }


            }

        }
    }



}