switch (index % 6)
{
    case 0: dc.SetPen(wxPen(*wxBLUE,width));break;
    case 1: dc.SetPen(wxPen(*wxRED,width));break;
    case 2: dc.SetPen(wxPen(yellow,width));break;
    case 3: dc.SetPen(wxPen(*wxBLACK,width));break;
    case 4: dc.SetPen(wxPen(*wxCYAN,width));break;
    case 5: dc.SetPen(wxPen(magenta,width));break;
}

switch (index / 6)
{
    case 0: dc.SetBrush(*wxRED);break;
    case 1: dc.SetBrush(*wxBLUE);break;
    case 2: dc.SetBrush(yellow);break;
    case 3: dc.SetBrush(*wxBLACK);break;
    case 4: dc.SetBrush(*wxWHITE);break;
    case 5: dc.SetBrush(*wxGREEN);break;
}
