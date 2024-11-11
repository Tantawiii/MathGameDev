//#include <SFML/Graphics.hpp>
//#include <vector>
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 300), "Parallax");
//    window.setFramerateLimit(60);
//
//    sf::Texture backgroundTexture1, backgroundTexture2, backgroundTexture3, backgroundTexture4;
//    if (!backgroundTexture1.loadFromFile("C:/Users/omart/OneDrive/Documents/GitHub/SfmlTests/MathDay1/SfmlTests/background_1.png") ||
//        !backgroundTexture2.loadFromFile("C:/Users/omart/OneDrive/Documents/GitHub/SfmlTests/MathDay1/SfmlTests/background_2.png") ||
//        !backgroundTexture3.loadFromFile("C:/Users/omart/OneDrive/Documents/GitHub/SfmlTests/MathDay1/SfmlTests/background_3.png") ||
//        !backgroundTexture4.loadFromFile("C:/Users/omart/OneDrive/Documents/GitHub/SfmlTests/MathDay1/SfmlTests/background_4.png")) {
//        return -1;
//    }
//
//    sf::Sprite layer1(backgroundTexture1);
//    sf::Sprite layer2(backgroundTexture2);
//    sf::Sprite layer3(backgroundTexture3);
//    sf::Sprite layer4(backgroundTexture4);
//
//    float windowWidth = window.getSize().x;
//    float windowHeight = window.getSize().y;
//    layer1.setScale(windowWidth / backgroundTexture1.getSize().x, windowHeight / backgroundTexture1.getSize().y);
//    layer2.setScale(windowWidth / backgroundTexture2.getSize().x, windowHeight / backgroundTexture2.getSize().y);
//    layer3.setScale(windowWidth / backgroundTexture3.getSize().x, windowHeight / backgroundTexture3.getSize().y);
//    layer4.setScale(windowWidth / backgroundTexture4.getSize().x, windowHeight / backgroundTexture4.getSize().y);
//
//    float layer1Speed = 10.0f;
//    float layer2Speed = 20.0f;
//    float layer3Speed = 30.0f;
//    float layer4Speed = 40.0f;
//
//    float layer1Offset = 0.0f;
//    float layer2Offset = 0.0f;
//    float layer3Offset = 0.0f;
//    float layer4Offset = 0.0f;
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
//        layer1Offset -= layer1Speed * deltaTime;
//        layer2Offset -= layer2Speed * deltaTime;
//        layer3Offset -= layer3Speed * deltaTime;
//        layer4Offset -= layer4Speed * deltaTime;
//
//        float layer1Width = layer1.getLocalBounds().width * layer1.getScale().x;
//        float layer2Width = layer2.getLocalBounds().width * layer2.getScale().x;
//        float layer3Width = layer3.getLocalBounds().width * layer3.getScale().x;
//        float layer4Width = layer4.getLocalBounds().width * layer4.getScale().x;
//
//        if (layer1Offset <= -layer1Width) layer1Offset += layer1Width;
//        if (layer2Offset <= -layer2Width) layer2Offset += layer2Width;
//        if (layer3Offset <= -layer3Width) layer3Offset += layer3Width;
//        if (layer4Offset <= -layer4Width) layer4Offset += layer4Width;
//
//        window.clear();
//        layer1.setPosition(layer1Offset, 0);
//        window.draw(layer1);
//        layer1.setPosition(layer1Offset + layer1Width, 0);
//        window.draw(layer1);
//
//        layer2.setPosition(layer2Offset, 0);
//        window.draw(layer2);
//        layer2.setPosition(layer2Offset + layer2Width, 0);
//        window.draw(layer2);
//
//        layer3.setPosition(layer3Offset, 0);
//        window.draw(layer3);
//        layer3.setPosition(layer3Offset + layer3Width, 0);
//        window.draw(layer3);
//
//        layer4.setPosition(layer4Offset, 0);
//        window.draw(layer4);
//        layer4.setPosition(layer4Offset + layer4Width, 0);
//        window.draw(layer4);
//
//        window.display();
//    }
//
//    return 0;
//}