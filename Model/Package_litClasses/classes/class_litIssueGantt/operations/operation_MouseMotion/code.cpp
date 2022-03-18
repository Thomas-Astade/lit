int x,y;
CalcUnscrolledPosition(event.m_x,event.m_y,&x,&y);

y -= upperBorder;
y /= textHeight + textDistance;
y -= 2;

if (y >= 0 && y < static_cast<int>((*myIssues).size()))
{
    int daysFromBegin = (wxTimeSpan::Minutes(61)+(*myIssues)[y]->GetStart().Subtract(firstDate)).GetDays();
    int issueDays = (wxTimeSpan::Minutes(61)+(*myIssues)[y]->GetEnd().Subtract((*myIssues)[y]->GetStart())).GetDays();
    int issuePixel = issueDays * pixelPerDay;
    int startPixel = leftBorder + nameWidth + (2 * textBorder) + daysFromBegin * pixelPerDay;

    if (abs(startPixel - x) <= 2)
    {
        SetCursor(wxCursor(wxCURSOR_SIZEWE));
        couldChangeLeft = true;
        couldChangeRight = false;
    }
    else if (abs((startPixel + issuePixel) - x) <= 2)
    {
        SetCursor(wxCursor(wxCURSOR_SIZEWE));
        couldChangeLeft = false;
        couldChangeRight = true;
    }
    else if ((startPixel < x) && ((startPixel + issuePixel) > x))
    {
        SetCursor(wxCursor(wxCURSOR_HAND));
        couldChangeLeft = true;
        couldChangeRight = true;
    }
    else
    {
        SetCursor(wxNullCursor);
        couldChangeLeft = false;
        couldChangeRight = false;
    }
}
else
    SetCursor(wxNullCursor);

if (downPosX < 0)
    return;

if (selectedItem < 0)
    return;

if (event.LeftIsDown())
{
    int timediff = (x - downPosX) * 24 / pixelPerDay;

    wxDateTime newStart;
    wxDateTime newEnd;

    newEnd = (*myIssues)[selectedItem]->GetEnd();
    newStart = (*myIssues)[selectedItem]->GetStart();

    if (changeRight)
        newEnd = (*myIssues)[selectedItem]->GetEnd()+wxTimeSpan::Hours(timediff);

    if (changeLeft)
        newStart = (*myIssues)[selectedItem]->GetStart()+wxTimeSpan::Hours(timediff);

    if (newStart < newEnd && (changeRight || changeLeft))
    {
        if (!event.AltDown())
            (*myIssues)[selectedItem]->SetStart(newStart);

        if (!event.ControlDown())
            (*myIssues)[selectedItem]->SetEnd(newEnd);

        downPosX = x;
        Refresh();
        litFrame* frame = dynamic_cast<litFrame*>(wxTheApp->GetTopWindow());
        if (frame)
            frame->SetCalenderValues();
    }
}
