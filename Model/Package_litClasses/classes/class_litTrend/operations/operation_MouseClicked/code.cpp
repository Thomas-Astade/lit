if (myIssues->empty())
    return;
    
int x,y;
CalcUnscrolledPosition(event.m_x,event.m_y, &x, &y);
event.Skip();

int textBorder = (textHeight + textDistance) * 2;

if (selectedItem < 0)
    selectedItem = 0;

int i = selectedItem;

do
{
    i++;
    if (static_cast<unsigned>(i) >= myIssues->size())
        i = 0;
    std::map<wxDateTime,wxDateTime> aChangeList = (*myIssues)[i]->GetChangeList();
    std::map<wxDateTime,wxDateTime>::iterator it;

    for (it = aChangeList.begin(); it != aChangeList.end(); it++)
    {
        int dx = (*it).first.Subtract(firstDate).GetDays();
        int dy = lastDate.Subtract((*it).second).GetDays();
        dx = textBorder + dx*pixelPerDay + leftBorder - 2;
        dy = textBorder + dy*pixelPerDay + upperBorder;
        
        int div1 = dx-x;
        int div2 = dy-y;
        
        if ((div1*div1 + div2*div2) < 15)
        {
            litFrame* frame = dynamic_cast<litFrame*>(wxTheApp->GetTopWindow());
            if (frame)
                frame->SelectItem(i);
            return;
        }
    }
} while (i != selectedItem);
