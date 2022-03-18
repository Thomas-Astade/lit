int textBorder = (textHeight + textDistance) * 2;
return textBorder + leftBorder + rightBorder + (pixelPerDay * lastDate.Subtract(firstDate).GetDays());
