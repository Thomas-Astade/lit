dc.SetPen(*wxBLACK_PEN);
int textBorder = (textHeight + textDistance) * 2;

for (unsigned int i = 0; i < myIssues->size(); i++)
{
    if (i == static_cast<unsigned>(selectedItem))
        SetIndexColor(dc,i,5);
    else
        SetIndexColor(dc,i,2);

    std::map<wxDateTime,wxDateTime> aChangeList = (*myIssues)[i]->GetChangeList();
    std::map<wxDateTime,wxDateTime>::iterator it;
    int xBefore = -1;
    int yBefore = -1;
    
    for (it = aChangeList.begin(); it != aChangeList.end(); it++)
    {
        int dx = (*it).first.Subtract(firstDate).GetDays();
        int dy = lastDate.Subtract((*it).second).GetDays();
        dx = textBorder + dx*pixelPerDay + leftBorder;
        dy = textBorder + dy*pixelPerDay + upperBorder;
        if (xBefore != -1)
        {
            dc.DrawLine(xBefore,yBefore,dx,dy);
        }
        xBefore = dx;
        yBefore = dy;
    }
    
    SetIndexColor(dc,i,1);

    for (it = aChangeList.begin(); it != aChangeList.end(); it++)
    {
        int dx = (*it).first.Subtract(firstDate).GetDays();
        int dy = lastDate.Subtract((*it).second).GetDays();
        dx = textBorder + dx*pixelPerDay + leftBorder - 2;
        dy = textBorder + dy*pixelPerDay + upperBorder;
        dc.DrawCircle(dx, dy, 5);
    }
}
