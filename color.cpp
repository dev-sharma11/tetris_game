#include"color.h"

const Color darkgray = {26,31,40,225};
const Color green = {47,230,23,225};
const Color red = {232,18,18,225};
const Color orange = {226,116,37,225};
const Color yellow = {237,234,4,225};
const Color purple = {166,0,247,225};
const Color cyan = {21,203,209,225};
const Color blue = {13,64,216,225};
const Color lightblue = {59,85,162,225};

std::vector<Color>getcellcolor(){
return {darkgray,green,red,orange,yellow,purple,cyan,blue};
}