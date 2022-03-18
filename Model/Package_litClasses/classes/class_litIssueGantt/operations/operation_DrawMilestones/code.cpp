wxPen aPen(*wxGREEN,3);
for (unsigned int i = 0; i < myIssues->size(); i++)
{
    if ((*myIssues)[i]->GetIsMilestone())
    {
        dc.SetPen(aPen);
	    int daysFromBegin = (wxTimeSpan::Minutes(61)+(*myIssues)[i]->GetStart().Subtract(firstDate)).GetDays();
	    int issueDays = (wxTimeSpan::Minutes(61)+(*myIssues)[i]->GetEnd().Subtract((*myIssues)[i]->GetStart())).GetDays();
	    int startPixel = leftBorder + nameWidth + (2 * textBorder) + daysFromBegin * pixelPerDay;
	    startPixel -= pixelPerDay;
	    int width  = issueDays * pixelPerDay;
	    width += (pixelPerDay);
		int height = (textHeight + textDistance) * (2 + myIssues->size());

	    dc.DrawLine(startPixel+width,
                    2 * (textHeight + textDistance) + upperBorder,
                    startPixel+width,
                    height + upperBorder);
    }
}
dc.SetPen(*wxGREEN_PEN);
