wxImageList* imageList = new wxImageList(16,16);

#include "yellow.h"
wxMemoryInputStream yellowstream(yellow_png, sizeof yellow_png);
imageList->Add(wxBitmap(wxImage(yellowstream, wxBITMAP_TYPE_PNG)));

#include "green.h"
wxMemoryInputStream greenstream(green_png, sizeof green_png);
imageList->Add(wxBitmap(wxImage(greenstream, wxBITMAP_TYPE_PNG)));

#include "red.h"
wxMemoryInputStream redstream(red_png, sizeof red_png);
imageList->Add(wxBitmap(wxImage(redstream, wxBITMAP_TYPE_PNG)));

#include "blue.h"
wxMemoryInputStream bluestream(blue_png, sizeof blue_png);
imageList->Add(wxBitmap(wxImage(bluestream, wxBITMAP_TYPE_PNG)));

#include "cyan.h"
wxMemoryInputStream cyanstream(cyan_png, sizeof cyan_png);
imageList->Add(wxBitmap(wxImage(cyanstream, wxBITMAP_TYPE_PNG)));

#include "grey.h"
wxMemoryInputStream greystream(grey_png, sizeof grey_png);
imageList->Add(wxBitmap(wxImage(greystream, wxBITMAP_TYPE_PNG)));

AssignImageList(imageList, wxIMAGE_LIST_SMALL);

InsertColumn(0, "Name");
InsertColumn(1, "End");
InsertColumn(2, "Project");
InsertColumn(3, "Resources");
