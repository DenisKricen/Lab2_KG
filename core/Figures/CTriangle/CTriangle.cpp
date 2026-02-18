#include "CTriangle.h"

CTriangle::CTriangle(int x, int y, int s) : centerX(x), centerY(y), size(s) {

}

void CTriangle::draw(QPainter& painter) {

    painter.setPen(QPen(Qt::red, 3));
    painter.save();
    painter.translate(centerX, centerY);

    QPolygon triangle;

    triangle << QPoint(0, 0) << QPoint(size, 0) << QPoint(0, size);
    painter.drawPolygon(triangle);

    painter.restore();
}

std::string CTriangle::getType() const {
    return "triangle";
}

std::string CTriangle::serialize() const {
    std::ostringstream oss;
    oss << centerX << " " << centerY << " " << size;
    return oss.str();
}

CTriangle* CTriangle::deserialize(const std::string& data) {
    std::istringstream iss(data);
    int x, y, s;
    iss >> x >> y >> s;
    return new CTriangle(x, y, s);
}