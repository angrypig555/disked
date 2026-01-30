#pragma once
#include<string>

inline int disk1_use;
inline int disk2_use;
inline int disk3_use;
inline int disk4_use;
// this will be updated later on, more disk capabiltiy will be added

inline int disk1_mounted;
inline int disk2_mounted;
inline int disk3_mounted;
inline int disk4_mounted;

inline std::string disk1_path; // these refer to the /dev/xyz path
inline std::string disk2_path;
inline std::string disk3_path;
inline std::string disk4_path;
// paths and sizes will be handled by manage-disk.cpp later on

std::string disk1_mount = "/mnt/disked/d1";
std::string disk2_mount = "/mnt/disked/d2";
std::string disk3_mount = "/mnt/disked/d3";
std::string disk4_mount = "/mnt/disked/d4";
// will be changed later on to get this from a config file
