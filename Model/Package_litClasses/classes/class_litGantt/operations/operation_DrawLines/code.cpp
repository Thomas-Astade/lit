dc.SetBrush(wxBrush(lightYellow));
dc.SetPen(wxPen(lightGrey));

int width = nameWidth + (pixelPerDay * lastDate.Subtract(firstDate).GetDays()) + (2 * textBorder);

for (unsigned int i = 0; i < myIssues->size(); i += 2)
{
    int y = (i+2)*(textHeight+textDistance);
    dc.DrawRectangle(leftBorder,y+upperBorder,width,textHeight+textDistance);
}

if (selectedItem >= 0)
{
    dc.SetBrush(wxBrush(lightRed));
    int y = (selectedItem+2)*(textHeight+textDistance);
    dc.DrawRectangle(leftBorder,y+upperBorder,width,textHeight+textDistance);
}
