#include <ios>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>

std::string katalog = "/tmp/smok/program-cpp/";
std::string nazwaPliku="/tmp/smok/program-cpp/smok-baza-danych.bin";
std::vector<std::uint8_t> wzorzec = {0x40,
0x24, 0x43, 0x48, 0xE8, 0x7E, 0xE1, 0x72, 0x83, 0x7A, 0x83,
0x8C, 0xAE, 0xAD, 0xBA, 0x6A, 0xF0, 0xE9, 0x5A, 0x49, 0xC1,
0x3D, 0x54, 0x5E, 0x55, 0x3D, 0x65, 0x3F, 0xD, 0xF9, 0x68,
0xB9, 0x50, 0xD7, 0x52, 0xBB, 0x3C, 0x44, 0x4E, 0x7, 0xAC,
0xF6, 0xD9, 0xA8, 0x73, 0xF8, 0x90, 0x5C, 0xA3, 0x79, 0x15,
0x7B, 0xF3, 0x7, 0xE1, 0xBB, 0x71, 0xD6, 0xC4, 0xFE, 0x95,
0xE4, 0xD, 0xC6};

int main()
{
  if(!std::filesystem::exists(katalog))
  {
    std::filesystem::create_directory(katalog);
  }
  if(std::filesystem::exists(nazwaPliku))
  {
    std::ifstream plik;
    plik.open(nazwaPliku, std::ios_base::binary);
    for(int i =0; i<wzorzec.size(); i++)
    {
      if(plik.eof())
      {
        std::cerr<<"Baza jest za krótka.\n";
        plik.close();
        exit(1);
      }
      uint8_t c = plik.get();
      if(c != wzorzec[i])
      {
        std::cerr<<"Baza uszkodzona.\n";
//        std::cerr<<std::hex<<"odczyt: "<<(int)c<<"wzor: "<<(int)wzorzec[i]<<" i: "<<i<<"\n";
        plik.close();
        exit(1);
      }
    }
    plik.close();
  }
  else
  {
    std::ofstream plik;
    plik.open(nazwaPliku, std::ios_base::binary);
    for(int i =0; i<wzorzec.size(); i++)
    {
      plik.put(wzorzec[i]);
    }
    plik.close();
  }
}
