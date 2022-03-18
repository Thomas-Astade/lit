if (myIssues->empty())
    return;

dc.SetBrush(lightYellow);
dc.SetPen(wxPen(lightGrey));

int textBorder = (textHeight + textDistance) * 2;

wxPoint points[3] = {
                        wxPoint(textBorder + leftBorder, textBorder + upperBorder),
                        wxPoint(textBorder + leftBorder + (pixelPerDay * lastDate.Subtract(firstDate).GetDays()), textBorder + upperBorder),
                        wxPoint(textBorder + leftBorder, textBorder + upperBorder + (pixelPerDay * lastDate.Subtract(firstDate).GetDays()))
                    };

dc.DrawPolygon(3,points);

DrawGrid(dc);
DrawIssues(dc);
