//#include <SFML/Graphics.hpp>
//#include <vector>
//
//const int NUM_CIRCLES = 30;
//const float INITIAL_RADIUS = 10.0f;
//const float LERP_SPEED = 0.2f;
//const sf::Color INITIAL_COLOR = sf::Color::White;
//
//sf::Vector2f lerp(const sf::Vector2f& start, const sf::Vector2f& end, float t) {
//    return start + (end - start) * t;
//}
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Trail");
//    window.setFramerateLimit(60);
//
//    std::vector<sf::CircleShape> circles(NUM_CIRCLES, sf::CircleShape(INITIAL_RADIUS));
//
//    for (int i = 0; i < NUM_CIRCLES; ++i) {
//        float radius = INITIAL_RADIUS * (1.0f - i * 0.03f);
//        circles[i].setRadius(radius);
//        circles[i].setOrigin(radius, radius);
//        sf::Uint8 opacity = static_cast<sf::Uint8>(200 * (1.0f - i * 0.03f));
//        circles[i].setFillColor(sf::Color(INITIAL_COLOR.r, INITIAL_COLOR.g, INITIAL_COLOR.b, opacity));
//    }
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        sf::Vector2f mousePos = (sf::Vector2f)sf::Mouse::getPosition(window);
//        circles[0].setPosition(mousePos);
//
//        for (int i = 1; i < NUM_CIRCLES; ++i) {
//            sf::Vector2f currentPos = circles[i].getPosition();
//            sf::Vector2f targetPos = circles[i - 1].getPosition();
//            sf::Vector2f newPos = lerp(currentPos, targetPos, LERP_SPEED);
//            circles[i].setPosition(newPos);
//        }
//
//        window.clear();
//        for (const auto& circle : circles) {
//            window.draw(circle);
//        }
//        window.display();
//    }
//
//    return 0;
//}
