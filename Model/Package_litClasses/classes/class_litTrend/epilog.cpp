BEGIN_EVENT_TABLE(litTrend, wxScrolledWindow)
  EVT_PAINT(litTrend::OnPaint)
  EVT_LEFT_DOWN(litTrend::MouseClicked)
END_EVENT_TABLE()
