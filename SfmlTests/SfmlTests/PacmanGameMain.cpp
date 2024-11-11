//#include <SFML/Graphics.hpp>
//#include <cmath>
//
//void updatePacman(sf::ConvexShape& shape, float radius, float startAngle, float endAngle) {
//    float startRad = startAngle * (3.14159265f / 180.f);
//    float endRad = endAngle * (3.14159265f / 180.f);
//    int pointCount = static_cast<int>(std::abs(endAngle - startAngle) / 5) + 2;
//    shape.setPointCount(pointCount + 1);
//    shape.setPoint(0, sf::Vector2f(0.f, 0.f));
//
//    for (int i = 0; i < pointCount; ++i) {
//        float angle = startRad + i * (endRad - startRad) / (pointCount - 1);
//        float x = radius * std::cos(angle);
//        float y = radius * std::sin(angle);
//        shape.setPoint(i + 1, sf::Vector2f(x, y));
//    }
//}
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Pac-Man");
//    window.setFramerateLimit(60);
//
//    sf::ConvexShape pacman;
//    float radius = 50.0f;
//
//    float baseStartAngle = 30.0f;
//    float baseEndAngle = 330.0f;
//    float angleRange = 30.0f;
//    float mouthSpeed = 5.0f;
//
//    float currentMouthAngle = 0.0f;
//    bool mouthOpening = true;
//
//    pacman.setFillColor(sf::Color::Yellow);
//    pacman.setOrigin(0.f, 0.f);
//    pacman.setPosition(400.f, 300.f);
//
//    sf::Clock clock;
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        float deltaTime = clock.restart().asSeconds();
//
//        if (mouthOpening) {
//            currentMouthAngle += mouthSpeed * deltaTime * 60.0f;
//            if (currentMouthAngle >= angleRange) {
//                currentMouthAngle = angleRange;
//                mouthOpening = false;
//            }
//        }
//        else {
//            currentMouthAngle -= mouthSpeed * deltaTime * 60.0f;
//            if (currentMouthAngle <= 0.0f) {
//                currentMouthAngle = 0.0f;
//                mouthOpening = true;
//            }
//        }
//
//        float startAngle = baseStartAngle - currentMouthAngle;
//        float endAngle = baseEndAngle + currentMouthAngle;
//
//        updatePacman(pacman, radius, startAngle, endAngle);
//
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
//            pacman.setRotation(180.0f);
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
//            pacman.setRotation(0.0f);
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
//            pacman.setRotation(270.0f);
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
//            pacman.setRotation(90.0f);
//        }
//
//        window.clear();
//        window.draw(pacman);
//        window.display();
//    }
//
//    return 0;
//}
