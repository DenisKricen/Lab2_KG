#include "CHexagon.h"

CHexagon::CHexagon() {

    size=0;
    centerX=0;
    centerY=0;

    fillColor= Qt::black;
    outColor= Qt::black;
}

void CHexagon::setProperties(CProperties& prop) {
    size=prop.circumradius;
    centerX=prop.abscise;    
    centerY=prop.ordinate;   
    fillColor=prop.fillColor;
    outColor=prop.outColor;
}

void CHexagon::draw(QPainter& painter) {
    QPen pen(outColor, 2);
    pen.setCosmetic(true);
    pen.setJoinStyle(Qt::MiterJoin);
    pen.setMiterLimit(10.0);
    
    painter.setPen(pen);
    painter.setBrush(fillColor);
    painter.save();
    
    painter.translate(centerX, -centerY);

    QPolygonF hexagon;
    for (int i = 0; i < 6; i++) {
        double angle = M_PI / 3.0 * i;
        double dx = size * cos(angle);
        double dy = size * sin(angle);
        
        hexagon << QPointF(dx, -dy);
    }
    painter.drawPolygon(hexagon);

    painter.restore();
}

std::string CHexagon::getType() const {
    return "hexagon";
}

std::string CHexagon::serialize() const {
    std::ostringstream oss;
    oss << centerX << " " << centerY << " " << size << " "
        << fillColor.red() << " " << fillColor.green() << " " << fillColor.blue() << " "
        << outColor.red() << " " << outColor.green() << " " << outColor.blue();
    return oss.str();
}

CHexagon* CHexagon::deserialize(const std::string& data) {
    std::istringstream iss(data);
    CHexagon* hex = new CHexagon();
    int fr, fg, fb, or_, og, ob;
    iss >> hex->centerX >> hex->centerY >> hex->size >> fr >> fg >> fb >> or_ >> og >> ob;
    hex->fillColor = QColor(fr, fg, fb);
    hex->outColor = QColor(or_, og, ob);
    return hex;
}