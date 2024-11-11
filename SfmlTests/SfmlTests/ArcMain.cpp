//#include <SFML/Graphics.hpp>
//#include <cmath>
//
//void updateArc(sf::ConvexShape& shape, const sf::Vector2f& center, float radius, float startAngle, float endAngle) {
//    float startRad = startAngle * (3.14159265f / 180.f);
//    float endRad = endAngle * (3.14159265f / 180.f);
//    int pointCount = static_cast<int>(std::abs(endAngle - startAngle) / 5) + 2;
//    shape.setPointCount(pointCount + 1);
//    shape.setPoint(0, center);
//
//    for (int i = 0; i < pointCount; ++i) {
//        float angle = startRad + i * (endRad - startRad) / (pointCount - 1);
//        float x = center.x + radius * std::cos(angle);
//        float y = center.y + radius * std::sin(angle);
//        shape.setPoint(i + 1, sf::Vector2f(x, y));
//    }
//}
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Arc");
//
//    sf::ConvexShape arc;
//    sf::Vector2f center(400, 300);
//    float radius = 100.0f;
//    float startAngle = 45.0f;
//    float endAngle = 135.0f;
//
//    updateArc(arc, center, radius, startAngle, endAngle);
//    arc.setFillColor(sf::Color::Green);
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        window.draw(arc);
//        window.display();
//    }
//
//    return 0;
//}
