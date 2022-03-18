dc.SetBrush(wxBrush(lightYellow));
int numberOfDays = lastDate.Subtract(firstDate).GetDays();
wxDateTime date = firstDate + wxTimeSpan::Minutes(61);
int textBorder = (textHeight + textDistance) * 2;

for (int i = 0; i < numberOfDays; i++)
{
    if (date.GetWeekDay() == wxDateTime::Sun)
        dc.SetPen(*wxBLACK_PEN);
    else
        dc.SetPen(wxPen(lightGrey));

   
    dc.DrawLine(textBorder + leftBorder,
                textBorder + upperBorder + (numberOfDays - i)*pixelPerDay,
                textBorder + leftBorder + i*pixelPerDay,
                textBorder + upperBorder + (numberOfDays - i)*pixelPerDay);

    date += wxTimeSpan::Day();
}

date = firstDate + wxTimeSpan::Minutes(61);

for (int i = 0; i < numberOfDays; i++)
{
    int daysThisMonth = wxDateTime::GetNumberOfDays(date.GetMonth(),date.GetYear());
    
    if (date.GetDay() == daysThisMonth && i >= daysThisMonth)
    {
        dc.SetPen(*wxBLACK_PEN);
        dc.DrawRectangle(textBorder + (i-daysThisMonth)*pixelPerDay + leftBorder,
                            upperBorder ,
                            daysThisMonth*pixelPerDay+1,textHeight + textDistance + 1);

        dc.DrawRectangle(leftBorder,
                            upperBorder + textBorder + (numberOfDays-i)*pixelPerDay,
                            textHeight + textDistance + 1, daysThisMonth*pixelPerDay+1);

        wxString monthText = date.Format("%b %Y");
        int x,y;
        dc.GetTextExtent(monthText,&x,&y);
        dc.DrawText(monthText,
                    textBorder + i*pixelPerDay - (daysThisMonth * pixelPerDay / 2) - (x / 2) + leftBorder,
                    2 + upperBorder);
        
        dc.DrawRotatedText(monthText,
                    leftBorder + 2,
                    upperBorder + textBorder + (numberOfDays-i)*pixelPerDay + (daysThisMonth * pixelPerDay / 2) + (x / 2), 90);
    }
    
    if (date.GetWeekDay() == wxDateTime::Sun)
    {
        dc.SetPen(*wxBLACK_PEN);

        if (i >= 7)
        {
            dc.DrawRectangle(textBorder + (i-7)*pixelPerDay + leftBorder,
                                textHeight + textDistance + upperBorder,
                                7*pixelPerDay+1, textHeight + textDistance);
            
            dc.DrawRectangle(textHeight + textDistance + leftBorder,
                                textBorder + upperBorder + (numberOfDays-i)*pixelPerDay,
                                textHeight + textDistance, 7*pixelPerDay+1);
            wxString weekText;
            weekText.Printf("%02d",date.GetWeekOfYear());
            int x,y;
            dc.GetTextExtent(weekText,&x,&y);
            dc.DrawText(weekText,
                        textBorder + i*pixelPerDay - (7 * pixelPerDay / 2) - (x / 2) + leftBorder,
                        2 + textHeight + textDistance + upperBorder);
        
            dc.DrawRotatedText(weekText,
                        textHeight + textDistance + leftBorder + 2,
                        upperBorder + textBorder + (numberOfDays-i)*pixelPerDay + (7 * pixelPerDay / 2) + (x / 2), 90);
            }
    }
    else
        dc.SetPen(wxPen(lightGrey));

   
    dc.DrawLine(textBorder + i*pixelPerDay + leftBorder,
                textBorder + upperBorder,
                textBorder + i*pixelPerDay + leftBorder,
                textBorder + (numberOfDays - i)*pixelPerDay + upperBorder);

    if (date.FormatISODate() == wxDateTime::Today().FormatISODate())
    {
        dc.SetPen(*wxRED_PEN);
        dc.DrawLine(textBorder + i*pixelPerDay-2 + leftBorder,
                    textBorder + upperBorder,
                    textBorder + i*pixelPerDay-2 + leftBorder,
                    textBorder + (numberOfDays - i)*pixelPerDay + upperBorder + 2);
    }
    
    date += wxTimeSpan::Day();
}
