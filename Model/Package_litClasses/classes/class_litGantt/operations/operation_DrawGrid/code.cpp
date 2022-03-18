dc.SetBrush(wxBrush(lightYellow));
int numberOfDays = lastDate.Subtract(firstDate).GetDays();
int height = (textHeight + textDistance) * (2 + myIssues->size());
wxDateTime date = firstDate + wxTimeSpan::Minutes(61);

for (int i=0; i<numberOfDays; i++)
{
    int daysThisMonth = wxDateTime::GetNumberOfDays(date.GetMonth(),date.GetYear());
    if ((date.GetDay() == daysThisMonth) && (i >= daysThisMonth))
    {
        dc.SetPen(*wxBLACK_PEN);
        dc.DrawRectangle((i-daysThisMonth)*pixelPerDay + leftBorder + nameWidth + (2 * textBorder),
                            upperBorder,
                            daysThisMonth * pixelPerDay + 1, textHeight + textDistance + 1);
        wxString monthText = date.Format("%b %Y");
        int x,y;
        dc.GetTextExtent(monthText,&x,&y);
        dc.DrawText(monthText,
                    i*pixelPerDay - (daysThisMonth * pixelPerDay / 2) - (x / 2) + leftBorder + nameWidth + (2 * textBorder),
                    2 + upperBorder);
    }
    
    if (date.GetWeekDay() == wxDateTime::Sun)
    {
        dc.SetPen(*wxBLACK_PEN);
        if (i >= 7)
        {
            dc.DrawRectangle((i-7)*pixelPerDay + leftBorder + nameWidth + (2 * textBorder),
                                textHeight + textDistance + upperBorder,
                                7*pixelPerDay+1,textHeight + textDistance);
            wxString weekText;
            weekText.Printf("%02d",date.GetWeekOfYear());
            int x,y;
            dc.GetTextExtent(weekText,&x,&y);
            dc.DrawText(weekText,
                        i*pixelPerDay - (7 * pixelPerDay / 2) - (x / 2) + leftBorder + nameWidth + (2 * textBorder),
                        2 + textHeight + textDistance + upperBorder);
        }
    }
    else
        dc.SetPen(wxPen(lightGrey));

    dc.DrawLine(i*pixelPerDay + leftBorder + nameWidth + (2 * textBorder),
                2 * (textHeight + textDistance) + upperBorder,
                i*pixelPerDay + leftBorder + nameWidth + (2 * textBorder),
                height + upperBorder);

    if (date.FormatISODate() == wxDateTime::Today().FormatISODate())
    {
        dc.SetPen(*wxRED_PEN);
        dc.DrawLine(i*pixelPerDay-2 + leftBorder + nameWidth + (2 * textBorder),
                    2 * (textHeight + textDistance) + upperBorder,
                    i*pixelPerDay-2 + leftBorder + nameWidth + (2 * textBorder),
                    height + upperBorder);
    }

    date += wxTimeSpan::Day();
}
