#include <stdlib.h>
#include <check.h>

#include "../src/GameState.h"
#include "../src/Player.h"
#include "../src/Card.h"

START_TEST(test_GameState_coherent_initialization)
{
	struct GameState *state = GameState_create();

}
END_TEST

Suite *GameState_suite(void) {
	Suite *s;
	TCase *tc_core;

	s = suite_create("GameState");

	tc_core = tcase_create("Core");
	tcase_add_test(tc_core, test_GameState_coherent_initialization);
	
	suite_add_tcase(s, tc_core);

	return s;
}

int main(void) {
	int failures;
	Suite *s;
	SRunner *sr;
	s = GameState_suite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_VERBOSE);
	failures = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (failures == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
