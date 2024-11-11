//#include <SFML/Graphics.hpp>
//#include <iostream>
//
//const float startHeight = 550;
//const float jumpHeight = 700;
//const float jumpDuration = 1.0f;
//
//float a, b, c;
//
//void calculateQuadraticCoefficients() {
//    float t1 = 0.0f;
//    float t2 = 0.5f;
//    float t3 = 1.0f;
//
//    float f1 = startHeight;
//    float f2 = startHeight - jumpHeight;
//    float f3 = startHeight;
//
//    c = f1;
//    b = (f2 - f1 - (t2 * t2 - t1 * t1) * (f3 - f1) / (t3 * t3 - t1 * t1)) / (t2 - t1);
//    a = (f3 - f1 - b * (t3 - t1)) / (t3 * t3 - t1 * t1);
//}
//
//int main() {
//    calculateQuadraticCoefficients();
//
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Jump");
//    window.setFramerateLimit(60);
//
//    sf::CircleShape circle(20.f);
//    circle.setFillColor(sf::Color::Blue);
//    circle.setOrigin(circle.getRadius(), circle.getRadius());
//    circle.setPosition(400, startHeight);
//
//    bool isJumping = false;
//    float elapsedTime = 0.0f;
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//
//            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
//                if (!isJumping) {
//                    isJumping = true;
//                    elapsedTime = 0.0f;
//                }
//            }
//        }
//
//        if (isJumping) {
//            elapsedTime += 1.0f / 60.0f;
//
//            float yPosition = a * elapsedTime * elapsedTime + b * elapsedTime + c;
//            circle.setPosition(400, yPosition);
//
//            if (elapsedTime >= jumpDuration) {
//                isJumping = false;
//                circle.setPosition(400, startHeight);
//            }
//        }
//
//        window.clear(sf::Color::Black);
//        window.draw(circle);
//        window.display();
//    }
//
//    return 0;
//}
