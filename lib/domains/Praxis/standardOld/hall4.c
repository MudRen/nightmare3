//Written by Lassondra of Sunshine

inherit "std/room";

void create() {
  ::create();
set_properties( ([ "light" : 1, "no castle" : 1 ]) );
set_short( "the Nightmare Inn" );
set_long( "The hallway is very quiet, you can barely hear the whisper "
"of your feet against the rich carpet. Large wooden doors for each room "
"stand both to your left and right, trimmed with gold. Small lanterns "
"hang every 5 feet or so, giving off a gentle glow, lighting the way." );
set_items( ([ "hallway" : "The hallway is very quiet.",
"carpet" : "It is a deep burgundy colour.",
({ "lanterns", "lanter" }) :
"The lanterns are gold with glass panes.",
"doors" : "The doors are large oaken barriers.",
]) );
set_exits( ([ "north" : "/domains/Praxis/hall5",
"south" : "/domains/Praxis/hall3",
"east" : "/domains/Praxis/inn107",
"west" : "/domains/Praxis/inn108",
]) );
set_pre_exit_functions( ({ "east", "west" }), ({ "room_107", "room_108" }) );
}
 
int room_107() {
if(present((string)"/domains/Praxis/hotel"->query_key_id(107),this_player()))
return 1;
write( "You cannot go in there!");
return 0;
}

int room_108() {
if(present((string)"/domains/Praxis/hotel"->query_key_id(108),this_player()))
return 1;
write( "You cannot go in there!");
return 0;
}
