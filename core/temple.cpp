// Qt drawing cheatsheet (QPainter basics)
// This file is a quick reference for common drawing calls used in this project.

#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QPolygon>
#include <QPoint>
#include <QRect>
#include <QFont>
#include <QFontMetrics>

void drawCheatsheet(QPainter& painter, int w, int h) {
    // Quality
    painter.setRenderHint(QPainter::Antialiasing);

    // Pen + Brush
    QPen pen(Qt::black, 2);
    pen.setCosmetic(true); // keep thickness constant when scaling
    painter.setPen(pen);
    painter.setBrush(QBrush(Qt::red));

    // Lines, rectangles, circles
    painter.drawLine(10, 10, 200, 10);
    painter.drawRect(10, 20, 80, 40);
    painter.drawEllipse(110, 20, 60, 60);

    // Polygon (triangle example)
    QPolygon tri;
    tri << QPoint(10, 100) << QPoint(60, 160) << QPoint(110, 100);
    painter.drawPolygon(tri);

    // Text
    painter.setFont(QFont("Arial", 12));
    painter.drawText(10, 190, "Hello Qt");
    painter.drawText(QRect(10, 200, 120, 40), Qt::AlignCenter, "Centered");

    // Text sizing
    QFontMetrics fm(painter.font());
    int textW = fm.horizontalAdvance("123");
    int textH = fm.height();
    painter.drawRect(10, 250, textW, textH);
    painter.drawText(10, 250 + textH, "123");

    // Save/restore state
    painter.save();
    painter.translate(w / 2, h / 2);
    painter.scale(1.5, 1.5);
    painter.rotate(15);
    painter.drawLine(-30, 0, 30, 0);
    painter.restore();
}
