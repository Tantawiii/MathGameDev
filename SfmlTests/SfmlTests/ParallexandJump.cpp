#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

const float startHeight = 500;
const float jumpHeight = 200;
const float jumpDuration = 1.0f;
const float windowWidth = 800;
const float windowHeight = 600;
float a, b, c;

void calculateQuadraticCoefficients() {
    float t1 = 0.0f;
    float t2 = 0.5f;
    float t3 = 1.0f;

    float f1 = startHeight;
    float f2 = startHeight - jumpHeight;
    float f3 = startHeight;

    c = f1;
    b = (f2 - f1 - (t2 * t2 - t1 * t1) * (f3 - f1) / (t3 * t3 - t1 * t1)) / (t2 - t1);
    a = (f3 - f1 - b * (t3 - t1)) / (t3 * t3 - t1 * t1);
}

sf::Vector2f lerp(const sf::Vector2f& start, const sf::Vector2f& end, float t) {
    return start + (end - start) * t;
}

int main() {
    calculateQuadraticCoefficients();

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Parallax Jump with Sprite");
    window.setFramerateLimit(20);

    sf::Texture backgroundTexture1, backgroundTexture2, backgroundTexture3, backgroundTexture4;
    backgroundTexture1.loadFromFile("C:/Users/omart/OneDrive/Documents/GitHub/MathGameDev/SfmlTests/background_1.png");
    backgroundTexture2.loadFromFile("C:/Users/omart/OneDrive/Documents/GitHub/MathGameDev/SfmlTests/background_2.png");
    backgroundTexture3.loadFromFile("C:/Users/omart/OneDrive/Documents/GitHub/MathGameDev/SfmlTests/background_3.png");
    backgroundTexture4.loadFromFile("C:/Users/omart/OneDrive/Documents/GitHub/MathGameDev/SfmlTests/background_4.png");

    sf::Sprite layer1(backgroundTexture1);
    sf::Sprite layer2(backgroundTexture2);
    sf::Sprite layer3(backgroundTexture3);
    sf::Sprite layer4(backgroundTexture4);

    layer1.setScale(windowWidth / backgroundTexture1.getSize().x, windowHeight / backgroundTexture1.getSize().y);
    layer2.setScale(windowWidth / backgroundTexture2.getSize().x, windowHeight / backgroundTexture2.getSize().y);
    layer3.setScale(windowWidth / backgroundTexture3.getSize().x, windowHeight / backgroundTexture3.getSize().y);
    layer4.setScale(windowWidth / backgroundTexture4.getSize().x, windowHeight / backgroundTexture4.getSize().y);

    float layer1Speed = 10.0f, layer2Speed = 20.0f, layer3Speed = 30.0f, layer4Speed = 40.0f;
    float layer1Offset = 0.0f, layer2Offset = 0.0f, layer3Offset = 0.0f, layer4Offset = 0.0f;

    sf::Texture adventurerTextures[4];
    adventurerTextures[0].loadFromFile("C:/Users/omart/OneDrive/Documents/GitHub/MathGameDev/SfmlTests/adventurer-jump-00.png");
    adventurerTextures[1].loadFromFile("C:/Users/omart/OneDrive/Documents/GitHub/MathGameDev/SfmlTests/adventurer-jump-01.png");
    adventurerTextures[2].loadFromFile("C:/Users/omart/OneDrive/Documents/GitHub/MathGameDev/SfmlTests/adventurer-jump-02.png");
    adventurerTextures[3].loadFromFile("C:/Users/omart/OneDrive/Documents/GitHub/MathGameDev/SfmlTests/adventurer-jump-03.png");

    sf::Sprite adventurerSprite(adventurerTextures[0]);
    adventurerSprite.setPosition(20, startHeight);
    adventurerSprite.setScale(2.0f, 2.0f);

    bool isJumping = false;
    float elapsedTime = 0.0f;
    int frameIndex = 0;
    sf::Clock frameClock;
    sf::Clock parallaxClock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                if (!isJumping) {
                    isJumping = true;
                    elapsedTime = 0.0f;
                    frameIndex = 0;
                }
            }
        }

        float deltaTime = parallaxClock.restart().asSeconds();
        layer1Offset -= layer1Speed * deltaTime;
        layer2Offset -= layer2Speed * deltaTime;
        layer3Offset -= layer3Speed * deltaTime;
        layer4Offset -= layer4Speed * deltaTime;

        float layer1Width = layer1.getLocalBounds().width * layer1.getScale().x;
        float layer2Width = layer2.getLocalBounds().width * layer2.getScale().x;
        float layer3Width = layer3.getLocalBounds().width * layer3.getScale().x;
        float layer4Width = layer4.getLocalBounds().width * layer4.getScale().x;

        if (layer1Offset <= -layer1Width) layer1Offset += layer1Width;
        if (layer2Offset <= -layer2Width) layer2Offset += layer2Width;
        if (layer3Offset <= -layer3Width) layer3Offset += layer3Width;
        if (layer4Offset <= -layer4Width) layer4Offset += layer4Width;

        if (isJumping) {
            elapsedTime += 1.0f / 20.0f;

            if (frameClock.getElapsedTime().asSeconds() > 0.1f) {
                frameIndex = (frameIndex + 1) % 4; 
                adventurerSprite.setTexture(adventurerTextures[frameIndex]);
                frameClock.restart();
            }

            float yPosition = a * elapsedTime * elapsedTime + b * elapsedTime + c;
            adventurerSprite.setPosition(20, yPosition);

            if (elapsedTime >= jumpDuration) {
                isJumping = false;
                adventurerSprite.setPosition(20, startHeight);
                adventurerSprite.setTexture(adventurerTextures[0]);
            }
        }

        window.clear();

        layer1.setPosition(layer1Offset, 0);
        window.draw(layer1);
        layer1.setPosition(layer1Offset + layer1Width, 0);
        window.draw(layer1);

        layer2.setPosition(layer2Offset, 0);
        window.draw(layer2);
        layer2.setPosition(layer2Offset + layer2Width, 0);
        window.draw(layer2);

        layer3.setPosition(layer3Offset, 0);
        window.draw(layer3);
        layer3.setPosition(layer3Offset + layer3Width, 0);
        window.draw(layer3);

        layer4.setPosition(layer4Offset, 0);
        window.draw(layer4);
        layer4.setPosition(layer4Offset + layer4Width, 0);
        window.draw(layer4);

        window.draw(adventurerSprite);

        window.display();
    }

    return 0;
}
