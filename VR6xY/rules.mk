CONSOLE_ENABLE = no
COMMAND_ENABLE = no
ORYX_ENABLE = yes
RGB_MATRIX_CUSTOM_KB = yes
SPACE_CADET_ENABLE = no

# Custom codes
LTO_ENABLE = yes

SRC += features/achordion.c
SRC += features/autocorrection.c
SRC += features/select_word.c
SRC += features/sentence_case.c
SRC += features/custom_shift_keys.c

REPEAT_KEY_ENABLE = yes
LAYER_LOCK_ENABLE = yes
CAPS_WORD_ENABLE = yes
REPEAT_KEY_ENABLE = yes
COMBO_ENABLE = yes
TAP_DANCE_ENABLE = yes
