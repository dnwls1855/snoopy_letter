#define _CRT_SECURE_NO_WARNINGS
#include <bangtal>
#include <iostream>
#include <stdio.h>
using namespace bangtal;


void Letter_init() {

	ScenePtr Snoopy_Letter = Scene::create("편지", "Images/letter_page.png");
	ScenePtr Letter_text1 = Scene::create("편지", "Images/letter_page1.png");
	ScenePtr Letter_text2 = Scene::create("편지", "Images/letter_page2.png");
	ScenePtr Letter_text3 = Scene::create("편지", "Images/letter_page3.png");
	
	ObjectPtr letter_text1 = Object::create("Images/letter_text1.png", Letter_text1, 0, 0);
	ObjectPtr letter_text2 = Object::create("Images/letter_text2.png", Letter_text1, 0, 0);
	letter_text2->hide();
	ObjectPtr letter_text3 = Object::create("Images/letter_text3.png", Letter_text2, 0, 0);
	
	int game_on = 0;
	int text_index = 0;
	int postbox_on = 0;
	ObjectPtr word[88];
	int word_x = 325;
	int word_y = 580;
	int word_index = 0;

	ObjectPtr next_button1 = Object::create("Images/next_button.png", Letter_text1, 920, 40);
	next_button1 -> setOnMouseCallback([&](auto object, auto x, auto y, auto action)->bool {
		if (text_index == 0) {

			letter_text1->hide();
			letter_text2->show();
			text_index++;
		}
		else if (text_index == 1) {
			Letter_text2->enter();
			text_index--;
		}
		return true;

		});

	ObjectPtr next_button2 = Object::create("Images/next_button.png", Letter_text2, 920, 40);
	next_button2->setOnMouseCallback([&](auto object, auto x, auto y, auto action)->bool {
		Snoopy_Letter->enter();
		return true;

		});

	ObjectPtr Letter_page = Object::create("Images/letter.png", Snoopy_Letter, 223, 241);
	Letter_page->hide();

	ObjectPtr gamerule = Object::create("Images/letter_game_rule.png", Snoopy_Letter, 0, 0);
	
	ObjectPtr letter_text4 = Object::create("Images/letter_text4.png", Snoopy_Letter, 0, 0);
	letter_text4->hide();
	ObjectPtr ok_button4 = Object::create("Images/next_button.png", Snoopy_Letter, 920, 40);
	ok_button4->hide();

	ok_button4->setOnMouseCallback([&](auto object, auto x, auto y, auto action)->bool {
		letter_text4->hide();
		ok_button4->hide();
		return true;

		});

	ObjectPtr letter_text5 = Object::create("Images/letter_text5.png", Snoopy_Letter, 0, 0);
	letter_text5->hide();

	ObjectPtr ok_button5 = Object::create("Images/next_button.png", Snoopy_Letter, 920, 40);
	ok_button5->hide();

	ok_button5->setOnMouseCallback([&](auto object, auto x, auto y, auto action)->bool {
		letter_text5->hide();
		ok_button5->hide();
		postbox_on++;
		return true;

		});

	ObjectPtr letter_text6 = Object::create("Images/letter_text6.png", Snoopy_Letter, 0, 0);
	letter_text6->hide();

	ObjectPtr letter_text7 = Object::create("Images/letter_text7.png", Snoopy_Letter, 0, 0);
	letter_text7->hide();
	
	ObjectPtr letter_text8 = Object::create("Images/letter_text8.png", Snoopy_Letter, 0, 0);
	letter_text8->hide();

ObjectPtr next_button6 = Object::create("Images/next_button.png", Snoopy_Letter, 920, 40);
	next_button6->hide();

	next_button6->setOnMouseCallback([&](auto object, auto x, auto y, auto action)->bool {
		if (text_index == 0) {

			letter_text6->hide();
			letter_text7->show();
			text_index++;
		}

		else if (text_index == 1) {

			letter_text7->hide();
			letter_text8->show();
			text_index++;
		}

		else if (text_index == 2) {
			Letter_text3->enter();
			text_index = 0;
		}
		return true;

		});

	ObjectPtr letter_text9 = Object::create("Images/letter_text9.png", Letter_text3, 0, 0);

	ObjectPtr letter_text10 = Object::create("Images/letter_text10.png", Letter_text3, 0, 0);
	letter_text10->hide();

	ObjectPtr letter_text11 = Object::create("Images/letter_text11.png", Letter_text3, 0, 0);
	letter_text11->hide();

	ObjectPtr next_button9 = Object::create("Images/next_button.png", Letter_text3, 920, 40);

	next_button9->setOnMouseCallback([&](auto object, auto x, auto y, auto action)->bool {
		if (text_index == 0) {

			letter_text9->hide();
			letter_text10->show();
			text_index++;
		}

		else if (text_index == 1) {

			letter_text10->hide();
			letter_text11->show();
			text_index++;
		}

		else if (text_index == 2) {
			endGame();
			//여기가 끝!!
		}
		return true;

		});

	ObjectPtr postbox = Object::create("Images/postbox.png", Snoopy_Letter, 1070, 150);
	postbox->hide();
	postbox->setOnMouseCallback([&](auto object, auto x, auto y, auto action)->bool {
		if (postbox_on == 0) {
			letter_text4->show();
			ok_button4->show();
		}
		else if (postbox_on == 1){}
		else if (postbox_on == 2) {
			Letter_page->hide();
			letter_text6->show();
			next_button6->show();
			for (int i = 0; i < 86; i++)
			{
				word[i]->hide();
			}

		}

		return true;


		});

	ObjectPtr letter_start = Object::create("Images/letter_start.png", Snoopy_Letter, 500, 50);
	letter_start->setOnMouseCallback([&](auto object, auto x, auto y, auto action)->bool {
		gamerule->hide();
		Letter_page->show();
		postbox->show();
		game_on++;
		letter_start->hide();
		return true;

		});
	



	char path[30];
	for (int i = 0; i < 9; i++)
	{
		sprintf(path, "Images/snoopy_letter_%d.png", i);
		word[i] = Object::create(path, Snoopy_Letter, word_x + 25*i, word_y);
		word[i]->hide();
	}

	for (int i = 9; i < 25; i++)
	{
		sprintf(path, "Images/snoopy_letter_%d.png", i);
		word[i] = Object::create(path, Snoopy_Letter, word_x + 25 * (i-12), word_y - 50);
		word[i]->hide();
	}

	for (int i = 25; i < 41; i++)
	{
		sprintf(path, "Images/snoopy_letter_%d.png", i);
		word[i] = Object::create(path, Snoopy_Letter, word_x + 25 * (i - 28), word_y - 90);
		word[i]->hide();
	}

	for (int i = 41; i < 57; i++)
	{
		sprintf(path, "Images/snoopy_letter_%d.png", i);
		word[i] = Object::create(path, Snoopy_Letter, word_x + 25 * (i - 44), word_y - 130);
		word[i]->hide();
	}

	for (int i = 57; i < 73; i++)
	{
		sprintf(path, "Images/snoopy_letter_%d.png", i);
		word[i] = Object::create(path, Snoopy_Letter, word_x + 25 * (i - 60), word_y - 175);
		word[i]->hide();
	}

	for (int i = 73; i < 87; i++)
	{
		sprintf(path, "Images/snoopy_letter_%d.png", i);
		word[i] = Object::create(path, Snoopy_Letter, word_x + 25 * (i - 76), word_y - 220);
		word[i]->hide();
	}

	Snoopy_Letter->setOnKeyboardCallback([&](ScenePtr scene2, KeyCode code, bool pressed)->bool {
		if (pressed == true && word_index <= 86 && game_on == 1) {
			
			switch (code) {
			case KeyCode::KEY_SPACE: if (word_index < 87) { word[word_index]->show(); word_index++; }  break;
			}
			if (word_index == 87) {
				letter_text5->show();
				ok_button5->show();
				postbox_on++;
			}
		}
	return true;
});

	startGame(Letter_text1);
}

int main() {
	Letter_init();
}