dc.SetPen(*wxBLACK_PEN);
for (unsigned int i = 0; i < myIssues->size(); i++)
{
	switch ((*myIssues)[i]->GetState())
	{
	case 0:
		dc.SetBrush(wxBrush(yellow));
		break;
	case 1:
		dc.SetBrush(*wxGREEN_BRUSH);
		break;
	case 2:
		dc.SetBrush(*wxRED_BRUSH);
		break;
	case 3:
		dc.SetBrush(*wxBLUE_BRUSH);
		break;
	default:
		dc.SetBrush(wxBrush(magenta));
		break;
	}
    int daysFromBegin = (wxTimeSpan::Minutes(61)+(*myIssues)[i]->GetStart().Subtract(firstDate)).GetDays();
    int issueDays = (wxTimeSpan::Minutes(61)+(*myIssues)[i]->GetEnd().Subtract((*myIssues)[i]->GetStart())).GetDays();
    int startPixel = leftBorder + nameWidth + (2 * textBorder) + daysFromBegin * pixelPerDay;
    startPixel -= pixelPerDay;
    int width  = issueDays * pixelPerDay;
    width += (pixelPerDay);
    int y = upperBorder + 2*(textHeight + textDistance) + 2 + i*(textHeight+textDistance);
    dc.DrawRectangle(startPixel,y,width+1,textHeight);
}
