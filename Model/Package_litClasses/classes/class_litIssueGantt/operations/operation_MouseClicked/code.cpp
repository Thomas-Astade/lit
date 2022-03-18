int x,y;
CalcUnscrolledPosition(event.m_x,event.m_y,&x,&y);

downPosX = x;
changeRight = couldChangeRight;
changeLeft = couldChangeLeft;

y -= upperBorder;
y /= textHeight + textDistance;
y -= 2;
event.Skip();

litFrame* frame = dynamic_cast<litFrame*>(wxTheApp->GetTopWindow());
if (frame)
    frame->SelectItem(y);
