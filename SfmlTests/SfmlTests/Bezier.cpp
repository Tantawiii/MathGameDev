//#include <SFML/Graphics.hpp>
//#include <cmath>
//#include <vector>
//
//sf::Vector2f calculateBezierPoint(const sf::Vector2f& startPoint, const sf::Vector2f& controlPoint1, const sf::Vector2f& controlPoint2, const sf::Vector2f& endPoint, float t) {
//    float oneMinusT = 1 - t;
//    float tSquared = t * t;
//    float oneMinusTSquared = oneMinusT * oneMinusT;
//    float oneMinusTCubed = oneMinusTSquared * oneMinusT;
//    float tCubed = tSquared * t;
//
//    sf::Vector2f bezierPoint = oneMinusTCubed * startPoint;
//    bezierPoint += 3 * oneMinusTSquared * t * controlPoint1;
//    bezierPoint += 3 * oneMinusT * tSquared * controlPoint2;
//    bezierPoint += tCubed * endPoint;
//
//    return bezierPoint;
//}
//
//class DraggableControlPoint : public sf::CircleShape {
//public:
//    DraggableControlPoint(float x, float y) {
//        setRadius(8.0f);
//        setFillColor(sf::Color::White);
//        setOutlineThickness(2.0f);
//        setOutlineColor(sf::Color::Black);
//        setOrigin(8.0f, 8.0f);
//        setPosition(x, y);
//    }
//
//    bool isMouseOver(const sf::Vector2i& mousePosition) {
//        sf::Vector2f position = getPosition();
//        return std::sqrt(std::pow(position.x - mousePosition.x, 2) + std::pow(position.y - mousePosition.y, 2)) <= getRadius();
//    }
//};
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Bezier");
//    window.setFramerateLimit(60);
//
//    DraggableControlPoint startPoint(100, 500);
//    DraggableControlPoint controlPoint1(200, 100);
//    DraggableControlPoint controlPoint2(600, 100);
//    DraggableControlPoint endPoint(700, 500);
//
//    DraggableControlPoint* activeControlPoint = nullptr;
//
//    bool isAnimating = false;
//    float animationProgress = 0.0f;
//    sf::CircleShape animatedCircle(8.0f);
//    animatedCircle.setFillColor(sf::Color::Cyan);
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//
//            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
//                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
//
//                if (startPoint.isMouseOver(mousePosition)) activeControlPoint = &startPoint;
//                else if (controlPoint1.isMouseOver(mousePosition)) activeControlPoint = &controlPoint1;
//                else if (controlPoint2.isMouseOver(mousePosition)) activeControlPoint = &controlPoint2;
//                else if (endPoint.isMouseOver(mousePosition)) activeControlPoint = &endPoint;
//            }
//
//            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
//                activeControlPoint = nullptr;
//            }
//
//            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
//                isAnimating = true;
//                animationProgress = 0.0f;
//            }
//        }
//
//        if (activeControlPoint && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
//            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
//            activeControlPoint->setPosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
//        }
//
//        sf::VertexArray bezierCurve(sf::LineStrip, 100);
//        for (int i = 0; i < 100; ++i) {
//            float t = i / 99.0f;
//            sf::Vector2f point = calculateBezierPoint(startPoint.getPosition(), controlPoint1.getPosition(), controlPoint2.getPosition(), endPoint.getPosition(), t);
//            bezierCurve[i].position = point;
//
//            sf::Color gradientColor = sf::Color(255 * t, 255 * (1 - t), 255);
//            bezierCurve[i].color = gradientColor;
//        }
//
//        if (isAnimating) {
//            if (animationProgress <= 1.0f) {
//                sf::Vector2f position = calculateBezierPoint(startPoint.getPosition(), controlPoint1.getPosition(), controlPoint2.getPosition(), endPoint.getPosition(), animationProgress);
//                animatedCircle.setPosition(position.x - animatedCircle.getRadius(), position.y - animatedCircle.getRadius());
//                animationProgress += 0.005f;
//            }
//            else {
//                isAnimating = false;
//            }
//        }
//
//        window.clear();
//        window.draw(bezierCurve);
//        window.draw(startPoint);
//        window.draw(controlPoint1);
//        window.draw(controlPoint2);
//        window.draw(endPoint);
//
//        if (isAnimating) {
//            window.draw(animatedCircle);
//        }
//
//        window.display();
//    }
//
//    return 0;
//}
