#include <stdlib.h>
#include <check.h>

#include "../src/Player.h"
#include "../src/Card.h"

START_TEST(test_Player_default_name)
{
	struct Player *player1 = Player_create(NULL);
	ck_assert_str_eq(Player_name(player1), "Player1");
	char random_name[] = "Daniel";
	struct Player *player2 = Player_create(random_name);
	ck_assert_str_eq(Player_name(player2), "Daniel");
	struct Player *player3 = Player_create("Daniela");
	ck_assert_str_eq(Player_name(player3), "Daniela");
	struct Player *player4 = Player_create(NULL);
	ck_assert_str_eq(Player_name(player4), "Player4");
	Player_destroy(player1);
	Player_destroy(player2);
	Player_destroy(player3);
	Player_destroy(player4);
}
END_TEST

START_TEST(test_Player_unique_card_owner)
{
	struct Player *player1 = Player_create(NULL);
	struct Player *player2 = Player_create(NULL);
	struct Card **set = Card_create_set();
	Player_take_card(player1, set[2]);
	int res = Player_take_card(player1, set[2]);
	ck_assert(res == -1);
	Card_destroy_set(set);
	Player_destroy(player1);
	Player_destroy(player2);
}
END_TEST

Suite *Player_suite(void) {
	Suite *s;
	TCase *tc_core, *tc_presentation;

	s = suite_create("Player");

	tc_core = tcase_create("Core");
	tcase_add_test(tc_core, test_Player_unique_card_owner);

	tc_presentation = tcase_create("Presentation");
	tcase_add_test(tc_core, test_Player_default_name);
	
	suite_add_tcase(s, tc_core);
	suite_add_tcase(s, tc_presentation);

	return s;
}

int main(void) {
	int failures;
	Suite *s;
	SRunner *sr;
	s = Player_suite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_VERBOSE);
	failures = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (failures == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}