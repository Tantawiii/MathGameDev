//#include <SFML/Graphics.hpp>
//#include <cmath>
//
//float easeInOutQuad(float t) {
//    return t < 0.5 ? 2 * t * t : -1 + (4 - 2 * t) * t;
//}
//
//float easeOutCubic(float t) {
//    t -= 1;
//    return t * t * t + 1;
//}
//
//float easeInExpo(float t) {
//    return t == 0 ? 0 : std::pow(2, 10 * (t - 1));
//}
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Easing");
//    window.setFramerateLimit(60);
//
//    sf::CircleShape circle(20.f);
//    circle.setFillColor(sf::Color::Green);
//    circle.setOrigin(circle.getRadius(), circle.getRadius());
//    sf::Vector2f circlePos(400, 300); 
//    sf::Vector2f targetPos = circlePos;
//
//    float speed = 0.05f;
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
//        targetPos = sf::Vector2f(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
//
//        sf::Vector2f direction = targetPos - circlePos;
//        float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
//
//        if (distance > 0.1f) {
//            direction /= distance;
//            float easedSpeed = speed * easeInOutQuad(std::min(1.0f, distance / 100.f));
//            circlePos += direction * easedSpeed * distance;
//        }
//
//        circle.setPosition(circlePos);
//        window.clear(sf::Color::Black);
//        window.draw(circle);
//        window.display();
//    }
//
//    return 0;
//}
