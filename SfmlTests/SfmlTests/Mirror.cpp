//#include <SFML/Graphics.hpp>
//#include <cmath>
//
//const float POINT_RADIUS = 5.0f;
//
//class DraggablePoint : public sf::CircleShape {
//public:
//    DraggablePoint(float x, float y) {
//        setRadius(POINT_RADIUS);
//        setFillColor(sf::Color::Cyan);
//        setOrigin(POINT_RADIUS, POINT_RADIUS);
//        setPosition(x, y);
//    }
//
//    bool isMouseOver(const sf::Vector2i& mousePos) {
//        sf::Vector2f pos = getPosition();
//        return std::sqrt(std::pow(pos.x - mousePos.x, 2) + std::pow(pos.y - mousePos.y, 2)) <= POINT_RADIUS;
//    }
//};
//
//sf::Vector2f reflectPoint(const sf::Vector2f& point, const sf::Vector2f& linePoint1, const sf::Vector2f& linePoint2) {
//    sf::Vector2f lineDir = linePoint2 - linePoint1;
//    sf::Vector2f lineNormal(-lineDir.y, lineDir.x);
//    float len = std::sqrt(lineNormal.x * lineNormal.x + lineNormal.y * lineNormal.y);
//    lineNormal /= len;
//    float distance = ((point.x - linePoint1.x) * lineNormal.x + (point.y - linePoint1.y) * lineNormal.y) * 2.0f;
//    return point - lineNormal * distance;
//}
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Mirror");
//    window.setFramerateLimit(60);
//
//    DraggablePoint mirrorPoint1(400, 200);
//    DraggablePoint mirrorPoint2(400, 400);
//
//    DraggablePoint trianglePoint1(300, 300);
//    DraggablePoint trianglePoint2(350, 450);
//    DraggablePoint trianglePoint3(250, 450);
//
//    DraggablePoint* draggedPoint = nullptr;
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//
//            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
//                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
//                if (mirrorPoint1.isMouseOver(mousePos)) draggedPoint = &mirrorPoint1;
//                else if (mirrorPoint2.isMouseOver(mousePos)) draggedPoint = &mirrorPoint2;
//                else if (trianglePoint1.isMouseOver(mousePos)) draggedPoint = &trianglePoint1;
//                else if (trianglePoint2.isMouseOver(mousePos)) draggedPoint = &trianglePoint2;
//                else if (trianglePoint3.isMouseOver(mousePos)) draggedPoint = &trianglePoint3;
//            }
//
//            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
//                draggedPoint = nullptr;
//            }
//        }
//
//        if (draggedPoint && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
//            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
//            draggedPoint->setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
//        }
//
//        sf::VertexArray mirrorLine(sf::Lines, 2);
//        mirrorLine[0].position = mirrorPoint1.getPosition();
//        mirrorLine[0].color = sf::Color::Cyan;
//        mirrorLine[1].position = mirrorPoint2.getPosition();
//        mirrorLine[1].color = sf::Color::Cyan;
//
//        sf::VertexArray triangle(sf::Triangles, 3);
//        triangle[0].position = trianglePoint1.getPosition();
//        triangle[1].position = trianglePoint2.getPosition();
//        triangle[2].position = trianglePoint3.getPosition();
//        triangle[0].color = sf::Color::White;
//        triangle[1].color = sf::Color::White;
//        triangle[2].color = sf::Color::White;
//
//        sf::Vector2f reflectedPoint1 = reflectPoint(trianglePoint1.getPosition(), mirrorPoint1.getPosition(), mirrorPoint2.getPosition());
//        sf::Vector2f reflectedPoint2 = reflectPoint(trianglePoint2.getPosition(), mirrorPoint1.getPosition(), mirrorPoint2.getPosition());
//        sf::Vector2f reflectedPoint3 = reflectPoint(trianglePoint3.getPosition(), mirrorPoint1.getPosition(), mirrorPoint2.getPosition());
//
//        sf::VertexArray reflectedTriangle(sf::Triangles, 3);
//        reflectedTriangle[0].position = reflectedPoint1;
//        reflectedTriangle[1].position = reflectedPoint2;
//        reflectedTriangle[2].position = reflectedPoint3;
//        reflectedTriangle[0].color = sf::Color::Red;
//        reflectedTriangle[1].color = sf::Color::Green;
//        reflectedTriangle[2].color = sf::Color::Blue;
//
//        window.clear();
//        window.draw(mirrorLine);
//        window.draw(triangle);
//        window.draw(reflectedTriangle);
//        window.draw(mirrorPoint1);
//        window.draw(mirrorPoint2);
//        window.draw(trianglePoint1);
//        window.draw(trianglePoint2);
//        window.draw(trianglePoint3);
//        window.display();
//    }
//
//    return 0;
//}
