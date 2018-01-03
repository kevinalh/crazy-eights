#include <stdlib.h>
#include <check.h>

#include "../src/Player.h"

START_TEST(test_Player_default_name)
{
	struct Player *player = Player_create(NULL);
	ck_assert_str_eq(Player_name(player), "Player1");
	struct Player *player2 = Player_create(NULL);
	ck_assert_str_eq(Player_name(player2), "Player2");
	struct Player *player3 = Player_create(NULL);
	ck_assert_str_eq(Player_name(player3), "Player3");
}
END_TEST

Suite *Player_suite(void) {
	Suite *s;
	TCase *tc_core;

	s = suite_create("Player");

	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test_Player_default_name);
	suite_add_tcase(s, tc_core);

	return s;
}

int main(void) {
	int failures;
	Suite *s;
	SRunner *sr;
	s = Player_suite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	failures = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (failures == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}