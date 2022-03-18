for (unsigned int i = 0; i < myIssues->size(); i++)
    for (unsigned int j = 0; j < myIssues->size(); j++)
        if ((*myIssues)[i]->GetIsDependent((*myIssues)[j]))
        {
            int daysFromBegin1 = (wxTimeSpan::Minutes(61)+(*myIssues)[i]->GetEnd().Subtract(firstDate)).GetDays();
            int startPixel1 = leftBorder + nameWidth + (2 * textBorder) + daysFromBegin1 * pixelPerDay;
            int y1 = upperBorder + 2*(textHeight + textDistance) + 2 + i*(textHeight+textDistance) + textHeight/2;

            int daysFromBegin2 = (wxTimeSpan::Minutes(61)+(*myIssues)[j]->GetStart().Subtract(firstDate)).GetDays();
            int startPixel2 = leftBorder + nameWidth + (2 * textBorder) + daysFromBegin2 * pixelPerDay;
            startPixel2 -= pixelPerDay;
            int y2 = upperBorder + 2*(textHeight + textDistance) + 2 + j*(textHeight+textDistance);
            wxPoint points[3];
            int e2;
            
            if (y1 > y2)
            {
                y2 += textHeight-1;
                e2 = y2 + 3;
                points[0] = wxPoint(startPixel2,y2);
                points[1] = wxPoint(startPixel2-3,y2+5);
                points[2] = wxPoint(startPixel2+3,y2+5);
            }
            else
            {
                e2 = y2 - 3;
                points[0] = wxPoint(startPixel2,y2);
                points[1] = wxPoint(startPixel2-3,y2-5);
                points[2] = wxPoint(startPixel2+3,y2-5);
            }
             
            if (startPixel1 <= startPixel2)
                dc.SetPen(wxPen(*wxBLUE,3));
            else
                dc.SetPen(wxPen(*wxRED,3));

            dc.DrawLine(startPixel1,y1,startPixel2,y1);
            dc.DrawLine(startPixel2,y1,startPixel2,e2);

            if (startPixel1 <= startPixel2)
            {
                dc.SetPen(wxPen(*wxBLUE,1));
                dc.SetBrush(*wxBLUE_BRUSH);
            }
            else
            {
                dc.SetPen(wxPen(*wxRED,1));
                dc.SetBrush(*wxRED_BRUSH);
            }

            dc.DrawPolygon(3,points);
        }
