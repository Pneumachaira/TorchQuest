#include <iostream>
#include <limits>
using namespace std;

// PUT VARIABLES HERE

string pname;
string action;
int story;
int state = 0;
int area = 0;
int item;
int item0 = 0;
int item1 = 0;
int item2 = 0;
int item3 = 0;
int craftNum;
int victory;
int retry = 1;
string itemArr[6] = {"Flowers", "Blue Key", "Red Key", "Sword", "Sticks", "Torches"};
int itemNum[6] = {0, 0, 0, 0, 0, 0};

// PUT FUNCTIONS HERE

void openHelp() {
	cout << "--- Help ---\ninventory\ngive.item\nlook.around\npickup.item\ngo.direction\nuse.item\ncraft.item\n-------------\n"; }
	
void noComprendo() {
	cout << "I don't understand.\n"; }

void inven() {
	cout << "-Inventory-";
	for (int x = 0; x <6; x++) {
		if (itemNum[x] > 0) {
		cout << endl << itemNum[x] << " " << itemArr[x]; }
	}
	cout << "\n-----------\n"; }

void crafting() {
		cout << ">> You have " << itemNum[4] << " sticks.  It takes 4 to craft a torch.  How many\ntorches do you wish to craft?\n";
		while (!(cin >> craftNum)){
    	cin.clear();
   	cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
	cout << "Invalid input, try again: "; }
	
	if (itemNum[4] - 4 * craftNum >= 0 && itemNum[4] - 4 * craftNum <= itemNum[4]) {
		cout << "You crafted " << craftNum << " torches!\n";
		itemNum[4] -= 4 * craftNum;
		itemNum[5] += craftNum; }
	else cout << "You do not have enough sticks.\n"; } // Closes crafting function

void actionCraft() {
			if (action == "craft.torches" && itemNum[4] < 4) {
				cout << ">> You don't have enough sticks.\n"; }
			if (action == "craft.torches" && itemNum[4] >= 4) {
				crafting(); }
}
	
// AREA FUNCTIONS HERE
void areaOne() {
	cout << ">> You find yourself in a garden, surrounded by beautiful flowers\nin a parade of different colors and shapes.\n"; }
void areaTwo() {
     cout << "Hedges and marble statues line the perimeter, and a large fountain is on display in the center.\n"; }
void areaThree() {
	cout << ">> You travel along a short wooded path.  To the east lies an\nornate bronze building, roughly the size and shape of an outhouse.\n"; }
void areaFour() {
	cout << ">> Huh.  It seems the luxurious outhouse was actually a shrine for\na magic sword.\n"; }
void areaFive() {
	cout << ">> You take a breath and glance ahead.  To the north looms the\nentrance to the castle, wherein lies the dragon that captured the\nprincess.\n" ; }
void areaNine() {
		cout << ">> You find yourself in what appears to be a young woman's room,\nsans the young woman.  A large mirror is covered in scorch marks.\nCountless dresses have been torn to shreds.  'TRUE LOVE' has been\nscraped an inch deep into the wall.  You hear stirring outside.\n" ; }

int areaState(int area, int state, int item){
	switch (area) {
		case 0:
		cout << ">> To the north you see the entrance to the castle.  To the west\nyou see a green gate.  To the south a blue gate.  To the east a\nred gate.\n";
		break;
		case 1:
		areaOne() ;
		if (item == 0) {
			cout << "One patch of flowers stands out from the rest.  There are also\nsome sticks on the ground.\n"; }
		if (item == 1) {
			cout << "There are some sticks on the ground.\n"; }
		if (item == 2) {
			cout << "One patch of flowers stands out from the rest.\n"; }
		if (item == 3) {
			cout << endl; }
			break;
			case 2:
			areaTwo() ;
			if (state == 0) {
				cout << "A squirrel is perched on the edge of the fountain.\n"; }
			if (state == 1) {
				cout << "The squirrel ran away.\n"; }
			if (item == 0) {
				cout << "There are some sticks next to a flying hippopotamus-\nshaped bush.\n"; }
			break;
			case 3:
			areaThree();
			if (state < 3) {
				cout << "Engraved on the door reads, 'What's brown and sticky?'\n" ; }
			if (item3 == 0) {
				cout << "A few feet to the left of the building lies a pile of sticks.\n" ; }
			break;
			case 4:
			areaFour();
			if (itemNum[3] == 0) {
				cout << "The sword hovers above a small pedestal.  Dust dances in a single\nsunbeam shining down on the sword.\n" ; }
			break;
			case 5:
			areaFive();
			if (state < 4) {
				cout << "The only way in is the drawbridge, which is currently raised.\nInscribed on the drawbridge's underside is a figure lifting a\nsword to the sun.\n" ; }
			if (state > 3) {
				cout << "The drawbridge is down.  The castle is open.  The dragon awaits.\n" ; }
			break;
			case 6:
			if (state < 5) {
				cout << ">> A dark corridor leads into the depths of the castle.  No way\nyou're going down there without being able to see anything.  If\nonly you could make something to light the path.  Hm, what a\ncrafty conundrum!\n" ; }
			if (state >= 5) {
				cout << ">> Torches line the brief hallway leading to the dragon's lair to\nthe north.  You peek into the room again.  Looks like the dragon\nis still asleep!\n" ; }
			break;
			case 8:
		cout << ">> The dragon slumbers.  On the west wall of the room there is a\nmysterious pink door.\n";
		if (itemNum[0] < 1) {
			cout << "You see your dad's inventory on the floor.  No sign of the rest of\nhim.\n" ; }
			break;
} // Closes switch statement
} // Closes areaState function

//////////////////////////////////////////////////
// MAIN FUNCTION STARTS HERE
//////////////////////////////////////////////////
int main() {
	while (retry == 1) {
	state = 0;
	victory = 0;
	itemNum[0] = 0;
	itemNum[1] = 0;
	itemNum[2] = 0;
	itemNum[3] = 0;
	itemNum[4] = 0;
	itemNum[5] = 0;
	
	cout << ">> Welcome to Torchquest!  Be sure to type in lower-case; I have a\nbit of a headache.  Oh, also do avoid spaces.  Type.like.this!\n";
	// Import intro program with minor adjustments?
	
// Determing story
	cout << ">> So what, may I ask, is the name of our brave and valiant hero?\n";
	cin >> pname;
	if (pname == "nextofkin"){
		story = 1; }
	else story = 0;
	// From here, the three stories branch out.  Start with story=0, by establishing the array tables and values.

while (itemNum[0] != 4) {
	
// START OF STORY ONE
	if (story == 0) {
			if (victory == 0) {
		cout << ">> The eagle you're riding on swoops down and lands in the\ncourtyard in front of the dragon's castle.  'This is as far as I\ncan take you,' he remarks pensively.  You start to wander towards\nthe castle as the eagle makes an obtrusive coughing sound.  'You\ngonna pay or what?'  Crap, you were hoping he forgot.  What do you do?\n";
		// Adjusting the value of the story allows for progression.  1 is when you ask for help.  2 is when you look at inventory.  3 is when you give gold.
	while (story < 3){
		cin >> action;
		if (action == "give.gold" || action == "help" || action == "inventory"){
			if (action == "give.gold") {
				story = 3; }
			if (action == "help") {
				openHelp() ;
				story = 1; }
			if (action == "inventory") {
				cout << ">> You dig through your pockets.  You've got some Gold.\n";
				story = 2; }
		} // This closes the first if statement
			else {
				state++;
				if (state < 3) {
					noComprendo() ; }
				if (state >= 3 && state < 5) {
					cout << ">> The eagle sighs with frustration and suggests asking for 'help'\nif you need to.\n"; }
				if (state >= 5) {
					switch (story) {
						case 0:			
				    	cout << ">> 'Look man, you're really killin' the whole immersion factor\nhere.  Type 'help' to see what your options are.'\n";
				    	break;
				    	case 1:
				    	cout << ">> 'Now that you know how to do so, why not check your 'inventory'\nto see if you even have anything to pay me with.'\n";
				    	break;
				    	case 2:
				    	cout << ">> 'You have the gold, so give it to me.'\n";
					} } // Ends the if statement
			} // Closes else statement
		} // Closes while loop, first tutorial part

		cout << ">> You begin to hand the money to the eagle.  Whoops!  You dropped\na coin!  The eagle just stares at you, his frustration simmering\ndown to a dull resignation.  You return a nervous smile.  Now where\ndid that darn thing go?\n";
		while (story <4) {
			cin >> action;
			if (action == "look.around" || action == "help" || action == "inventory" || action == "pickup.coin") {
			if (action == "look.around") {
				cout << ">> Ah, there's the coin!  It rolled underneath our eagle friend.\n";
				story = 4; }
			if (action == "help") {
				openHelp() ; }
			if (action == "inventory") {
				cout << ">> What inventory?  You just gave everything away or dropped it.\n"; }
				if (action == "pickup.coin") {
					cout << ">> You have to find the coin before you can pick it up.\n"; }
			} // Closes encompassing if statement
			else noComprendo() ;
		} // Closes tutorial part two
		while (story < 5) {
			cin >> action;
			if (action == "look.around" || action == "pickup.coin" || action == "help" || action == "inventory") {
					if (action == "look.around") {
					cout << ">> The coin is right there.\n"; }
					if (action == "pickup.coin") {
					story = 5;
				    cout << ">> You awkwardly circle around the eagle, searching out the least\nintrusive angle to reach underneath him for the coin.  The eagle\njust picks up the coin himself and flies off, muttering something\nabout Mondays.\n"; }
				    if (action == "help") {
				    	openHelp(); }
				    if (action == "inventory") {
				    	cout << ">> Still empty.\n"; }
				} // Closes if statement
			    else noComprendo() ;
		} // Closes tutorial part three
		cout << ">> Welp!  Time to get started!  Let's look around!\n";
		area = 0;
		state = 0;
		victory = 400;
			} // Closes tutorial if statement

// AREA ZERO
while (area == 0) {
		cin >> action;
		if (action == "help" || action == "look.around" || action == "go.north" || action == "go.west" || action == "go.south" || action == "go.east" || action == "craft.torches" || action == "inventory" || action == "use.bluekey" || action == "use.redkey" || action == "craft.torch") {
			if (action == "craft.torch") {
				action = "craft.torches"; }
			if (action == "help") openHelp();
			if (action == "look.around") areaState(0, 0, 0);
			if (action == "go.north") {
				cout << ">> You head towards the castle.\n";
				area = 5; }
			if (action == "go.west") {
				cout << ">> You head west through the green gate.\n";
				area = 1; }
			if (action == "go.south" && itemNum[1] == 0) {
					cout << ">> The blue gate is locked.\n"; }
			if ((action == "go.south" || action == "use.bluekey") && itemNum[1] == 1) {
					cout << ">> You use the blue key and head south through the blue gate.\n";
					area = 2; }
			if (action == "go.east" && itemNum[2] == 0) {
					cout << ">> The red gate is locked.\n"; }
			if ((action == "go.east" || action == "use.redkey") && itemNum[2] == 1) {
					cout << ">> You use the red key and head east through the red gate.\n";
					area = 3; }
			actionCraft();
			if (action == "inventory") inven() ;
			if (action == "use.bluekey" && itemNum[1] == 0) noComprendo();
			if (action == "use.redkey" && itemNum[2] == 0) noComprendo();
		} // Closes big if statement
		else noComprendo();
} // AREA ZERO COMPLETE
	} // Closes in Story 1 lock-in

// AREA ONE
if (area == 1) areaState(1, 0, item1) ;
while (area == 1) {
	cin >> action;
	if (action == "help" || action == "inventory" || action == "look.around" || action == "pickup.flowers" || action== "pickup.sticks" || action == "craft.torches" || action == "go.east" || action == "craft.torch") {
		if (action == "craft.torch") {
			action = "craft.torches" ; }
		if (action == "help") openHelp();
		if (action == "inventory") inven();
		if (action == "look.around") {
			areaState(1, 0, item1); }
		if (action == "pickup.flowers" && (item1 == 1 || item1 == 3)) {
			noComprendo() ; }
		if (action == "pickup.flowers" && (item1 == 0 || item1 == 2)) {
			cout << ">> You gingerly lift up some vibrant roses, and what's this?\nThere was a blue key beneath the roses!\n>> Got Flowers!  Got Blue Key!\n" ;
			itemNum[0] += 1;
			itemNum[1] += 1;
			if (item1 == 0) item1 = 1;
			if (item1 == 2) item1 = 3; }
			if (action == "pickup.sticks" && item1 >= 2) {
				noComprendo() ; }
		if (action == "pickup.sticks" && item1 < 2) {
			cout << ">> Ah, pick-up sticks, America's favorite pastime.  Or at least,\nthat's what you would say, if you had any concept of America. \nOr a pastime.  Curse you, 6th-century agrarian-based society that\nallows little to no free time for pick-up sticks!\n>> Er, anyway, you got 4 Sticks.\n";
			itemNum[4] += 4; 
			if (item1 == 0) item1 = 2;
			if (item1 == 1) item1 = 3; }
            actionCraft();
			if (action == "go.east") {
				area = 0;
				cout << ">> You head back east into the courtyard.\n" ; }
	}	// All of the if actions close here
	else noComprendo();
} // AREA ONE COMPLETE

if (area == 2) {
	if (itemNum[2] == 0) state = 0;
	areaState(2, state, item2); }
while (area == 2) {
	cin >> action;
	if (action == "help" || action == "inventory" || action == "look.around" || action == "pickup.squirrel" || action == "pickup.sticks" || action == "go.north" || action == "craft.torches" || action == "craft.torch") {
		if (action == "craft.torch") {
			action = "craft.torches" ; }
		if (action == "help") openHelp();
		if (action == "inventory") inven();
		if (action == "look.around") {
			areaState(2, state, item2); }
		if (action == "pickup.squirrel" && state != 0) {
			noComprendo(); }
		if (action == "pickup.squirrel" && state == 0) {
			cout << ">> Your eyes ablaze with determination, you deftly scoop the\nsquirrel into your hands.  As a reward for your quick reflexes,\nhe hands you a key and scampers off.\n>> Got Red Key!\n" ;
			itemNum[2] = 1;
			state = 2; }
		if (action == "pickup.sticks" && item2 == 1) {
			noComprendo() ; }
		if (action == "pickup.sticks" && item2 == 0) {
			cout << ">> Got 5 Sticks!  Whoa mama!\n";
			itemNum[4] += 5;
			item2 = 1;
		} // Closes if for picking up sticks
		if (action == "go.north") {
			area = 0;
			cout << ">> You head back north into the courtyard.\n" ; }
		actionCraft() ;
	} // Closes big if statement
	else noComprendo();
	if (itemNum[2] == 0) state = 1;
}  // AREA TWO COMPLETE


// AREA THREE
if (area == 3) areaState(3, state, item3);
while (area == 3) {
	cin >> action;
	if (action == "help" || action == "inventory" || action == "look.around" || action == "use.sticks" || action == "use.stick" || action == "pickup.sticks" || action == "go.west" || action == "go.east" || action == "craft.torches" || action == "craft.torch") {
		if (action == "craft.torch") {
			action = "craft.torches" ; }
		if (action == "help") openHelp();
		if (action == "inventory") inven();
		if (action == "look.around") {
			areaState(3, state, item3); }
		if ((action == "use.stick" || action == "use.sticks") && itemNum[4] > 0) {
			state = 3;
			cout << ">> You proudly wave a stick in the air, answering the riddle.  You\nknew having a terrible sense of humor would come in handy one day!\n>> The door opens.\n" ; }
		if ((action == "use.stick" || action == "use.sticks") && itemNum[4] == 0) {
			noComprendo() ; }
		if (action == "pickup.sticks" && item3 == 1) {
			noComprendo() ; }
		if (action == "pickup.sticks" && item3 == 0) {
			item3 = 1;
			itemNum[4] += 4;
			cout << ">> Got 4 Sticks!  Aw yeah!\n"; }
			if (action == "go.west") {
				area = 0;
				cout << ">> You head back west into the courtyard.\n" ; }
			if (action == "go.east" && state >= 3) {
				area = 4;
				cout << ">> You head into the bronze building.\n" ; }
			if (action == "go.east" && state < 3) {
				cout << ">> It's locked until you answer the riddle.\n" ; }
			actionCraft() ;
	} // Closes big if statement
	else noComprendo();
} // AREA THREE COMPLETE

if (area == 4) {
	areaState(4, state, 0); }
while (area == 4) {
	cin >> action;
	if (action == "help" || action == "inventory" || action == "look.around" || action == "pickup.sword" || action == "go.west" || action == "craft.torches" || action == "craft.torch") {
		if (action == "craft.torch" ) {
			action = "craft.torches" ; }
		if (action == "help") openHelp();
		if (action == "inventory") inven();
		if (action == "look.around") {
			areaState(4, state, 0); }
		actionCraft();
		if (action == "pickup.sword" && itemNum[3] == 1) {
			noComprendo() ; }
		if (action == "pickup.sword" && itemNum[3] == 0) {
			itemNum[3] = 1;
			cout << ">> Got Sword!  You go to raise it high above your head\ntriumphantly, but while attempting to do so you smack your hand on\nthe wall.  Stupid small outhouse sword shrine, you gripe, as you\nrub your bruised hand.\n" ; }
		if (action == "go.west") {
			area = 3;
			cout << ">> You exit the shrine, making sure to change the 'Occupied' sign\nto 'Vacant'.\n" ; }
	} // Closes big if statement
		else noComprendo() ;
} // AREA FOUR COMPLETE

if (area == 5) {
	areaState(5, state, 0) ; }
while (area == 5) {
	cin >> action;
	if (action == "help" || action == "inventory" || action == "look.around" || action == "use.sword" || action == "go.north" || action == "go.south" || action == "craft.torches" || action == "craft.torch") {
		if (action == "craft.torch") {
			action = "craft.torches" ; }
		if (action == "help") openHelp();
		if (action == "inventory") inven();
		if (action == "look.around") {
			areaState(5, state, 0); }
		actionCraft();
		if (action == "use.sword" && (state > 3 || itemNum[3] == 0)) {
			noComprendo() ; }
		if (action == "use.sword" && state <4 && itemNum[3] == 1) {
			cout << ">> You raise the sword high into the air.  Oh yeah, totally nailed\nit that time.  You then promptly sneeze.  Stupid old dusty magic\nsword.  The drawbridge lowers.\n" ;
			state = 4; }
		if (action == "go.north" && state > 3) {
			area = 6;
			cout << ">> You cross the bridge and head inside.\n" ; }
		if (action == "go.north" && state < 4) {
			cout << ">> You should probably lower the drawbridge first.\n" ; }
		if (action == "go.south") {
			area = 0;
			cout << ">> You head back south into the courtyard.\n" ; }
	} // Closes big if statement
	else noComprendo() ;
} // AREA FIVE COMPLETE

if (area == 6) {
	areaState(6, state, 0) ; }
while (area == 6) {
	cin >> action;
	if (action == "help" || action == "inventory" || action == "look.around" || action == "use.torches" || action == "go.north" || action == "craft.torches" || action == "craft.torch" || action == "go.south") {
		if (action == "craft.torch" ) {
			action = "craft.torches" ; }
		if (action == "help") openHelp();
		if (action == "inventory") inven();
		if (action == "look.around") {
			areaState(6, state, 0); }
		actionCraft();
		if (action == "use.torches" && itemNum[5] < 3) {
			cout << ">> You're gonna need more torches than that.\n" ; }
		if (action == "use.torches" && state < 5 && itemNum[5] == 3) {
			itemNum[5] -= 3;
			state = 5;
			cout << ">> You head north and begin to line the wall with torches.  One...\ntwo... three....  Huh.  You're already at the end.  That hallway\nwas a lot shorter than you thought.\n>> You peek through the iron window-bars of the door leading to\nthe dragon's chamber.  Perfect, the dragon is asleep!\n" ; }
		if (action == "go.south") {
			area = 5;
			cout << ">> You head back outside.\n" ; }
		if (action == "go.north" && state < 5) {
			cout << ">> Long dark hallways really aren't your thing.  Let's craft up\nsomething to light the way.\n" ; }
		if (action == "go.north" && state >= 5) {
			area = 7;
			cout << ">> Oh geez, I hope you're ready for this.  You head into the\ndragon's lair.\n" ; }
	} // Closes big if statement
	else noComprendo() ;
} // AREA SIX COMPLETE

// Area Seven - The Dragon's Lair - Visit One
if (area == 7) {
	cout << ">> You inch open the door and sneak in.  You creep up right behind\nthe dragon's head, where it's most vulnerable.  You know what to\ndo, hero!\n"; }
while (area == 7) {
while (state == 5) {
		cin >> action;
		if (action == "help" || action == "inventory" || action == "use.sword") {
			if (action == "help") openHelp() ;
			if (action == "inventory") inven() ;
			if (action == "use.sword") {
				state = 6;
				cout << ">> You raise the sword above your head and brace for impact....\nOh dear.  Your nose starts to twitch.\n" ; }
		} // Closes big if statement
		else {
			cout << ">> C'mon, you know what to do!\n" ; }
} // Closes first loop of Area Seven
cin >> action;
cout << ">> STUPID MAGIC DUST STUPID OUTHOUSE SWORD STUPID ALLERGIES STUPID\nSTUPID STUPID\n>> You sneeze.\n" ;
cin >> action;
cout << ">> The dragon rears up and spreads its wings, blocking the exit.\nA quick swipe of its tail knocks the sword from your hand.  As the\ndragon's gaping maw closes around your head, the last thing you see\nis some writing on the wall: 'nextofkin'.  Hey, that's your\nson's name!  How weird is tha--\n>> CHOMP.\n" ;
cin >> action;
cout << "--You have died.  Bad ending completed.--\n" ;
story = 2;
area = 20;
} // Closes Area Seven
while (state < 10 && area == 20) {
cout << ">> Would you like to retry and go for the good ending?  y/n: ";
cin >> action;
if (action == "y" || action == "n") {
	state = 10;
	itemNum[0] = 4;
	if (action == "y") {
		retry = 1; }
	if (action == "n") { // AREA 20, RETRY 0, STATE 10, STORY 2
		retry = 0;
		cout << ">> Thanks for playing!" ; }
} // Closes big if statement
else noComprendo();
} // Closes retry question
	
// STORY TWO STARTS HERE
if (story == 1) {
	if (victory == 0) {
cout << ">> Your name is Nextofkin, but your friends call you Kenny.  Your\ndad used to call you that too, before he got eaten by the dragon\nthat dwells behind this door.  But that's why you're here, to\navenge him.  And maybe to get a kiss from the princess.  That's\nhow these things work, right?  You're new to dating, so you're not\nentirely sure.\n" ;
victory = 400; }
while (state == 0) {
	cin >> action;
	if (action == "help" || action == "inventory" || action == "look.around" || action == "go.north" || action == "go.south") {
		if (action == "help") openHelp();
		if (action == "inventory") inven();
		if (action == "look.around") {
			cout << ">> You peek inside.  Looks like the dragon is sleeping.\n" ; }
		if (action == "go.south") {
			cout << ">> No turning back.\n"; }
		if (action == "go.north") {
			cout << ">> Deep breath.  Here we go.  You step through the door.\n" ; 
			area = 8;
			state = 1; }
	} // Closes big if statement
	else noComprendo() ;
} // Closes while loop
} // Closes if story = 1
// THE BODY OF STORY TWO IS HERE
	if (area == 8) {
		areaState(8, state, 0) ; }
	while (area == 8) {
		cin >> action;
		if (action == "help" || action == "inventory" || action == "look.around" || action == "pickup.inventory" || action == "use.sword" || action == "go.west") {
			if (action == "help") openHelp ();
			if (action == "inventory") inven() ;
			if (action == "look.around") {
				areaState (8, state, 0) ; }
			if (action == "pickup.inventory") {
				itemNum[0] = 1;
				itemNum[1] = 1;
				itemNum[2] = 1;
				itemNum[3] = 1;
				cout << ">> You retrieved your dad's stuff!  Got Flowers!  Got Blue Key!\nGot Red Key!  Got Sword!\n" ; }
			if (action == "use.sword" && itemNum[3] == 1) {
				cout << ">> You grip the magic sword, but that mysterious pink door beckons\nyou.  You need to see what's in there first.\n" ; }
				if (action == "use.sword" && itemNum[3] == 0) {
					noComprendo() ; }
				if (action == "go.west") {
					area = 9; 
					cout << ">> You tiptoe the long way around the room to avoid the dragon.\nThe pink door slowly creaks open, and you enter in.\n" ; }
		} // Closes big if statement
		else noComprendo() ;
	} // AREA EIGHT COMPLETE
	
	if (area == 9) {
		areaNine() ; }
		while (area == 9) {
		cin >> action;
		if (action == "help" || action == "inventory" || action == "look.around" || action == "go.east") {
			if (action == "help") openHelp() ;
			if (action == "inventory") inven() ;
			if (action == "look.around") {
				areaNine() ; }
			if (action == "go.east") {
				area = 10;
				cout << ">> Alright, time to finish things.  You hope checking out this\nroom was worth it....\n" ; }
		} // Closes big if statement
		else noComprendo() ;
	} // AREA NINE COMPLETE

// AREA TEN BEGIN - FINAL AREA
while (area == 10) {
	cout << ">> As you step outside, you're swept across the room by the\ndragon's tail.  The beast lets loose a powerful roar.  Do or die\ntime.\n" ;
	for (story = 0; story < 4; story++) {
		cin >> action;
		if (action == "help" || action == "inventory" || action == "look.around" || action == "use.flowers" || action == "give.flowers" || action == "use.sword") {
			if (action == "help") openHelp() ;
			if (action == "inventory") inven() ;
			if (action == "look.around") {
				cout << ">> Yup, there's a dragon.\n" ; }
			if (action == "use.flowers") {
				if (itemNum[0] == 1) {
				cout << ">> You brandish the flowers as a weapon, swiping them harmlessly\nback and forth.  Huh, maybe you should try something else with\nthose.\n" ; }
				else noComprendo() ; }
			if (action == "give.flowers") {
				if (itemNum[0] == 0) {
					noComprendo() ; }
				if (itemNum[0] == 1) {
				story = 10;
				area = 11;
				itemNum[0] = 4;
				cout << ">> You offer the flowers to the dragon, and it halts its advance.\nIt eyes over the flowers, and then sniffs them.  The dragon makes\nwhat almost sounds like a purring sound, and nuzzles you with its\nhead.  Are... are you supposed to kiss it, or what?  That's how\nthis thing works, right?  You're not entirely sure.  Suddenly, the\ndragon disappears in a brilliant light.  In its place stands the\nprincess.  You gulp and prepare your best pick-up line.\n>> You say: " ;
				cin >> action;
			cout << ">> You fumble over your words, but the princess finds it charming\nand laughs.  Ah geez, her smile makes your heart melt.  You walk\nout side by side, into the sunshine.\n" ;
			cout << "--Good ending achieved!  Great job, hero!--" ;
			retry = 0;}
			} // Closes big if statement
			if (action == "use.sword") {
				if (itemNum[3] == 0) {
					noComprendo() ; }
				if (itemNum[3] == 1) {
				if (story < 3) {
					cout << ">> Not yet.  Wait for it.\n" ; }
				if (story == 3) {
					cout << ">> Waiting for the perfect moment to strike, you leap forward past\nthe dragon's jaws and thrust the sword into the underside of its\nneck.  The dragon bellows a terrible guttural sound that turns\ninto gargling as it collapses to the ground and starts convulsing.\nThe dragon is dead.  You realize you were holding your breath that\nentire time, and breathe a deep sigh of relief.  You half-sit,\nhalf-collapse on the ground, exhausted, but victorious.\n" ;
					area = 11;
					cout << ">> The princess was never found.  Neutral ending achieved!  Try\nagain?  y/n: " ;
					while (state != 10) {
					cin >> action;
				if (action == "y" || action == "n") {
	state = 10;
	itemNum[0] = 4;
	if (action == "y") {
		retry = 1; }
	else {
		retry = 0;
		cout << ">> Thanks for playing!" ; }
		  }
else noComprendo(); } // Closes retry loop
				} // Closes winning action
				} // Closes sword == 1 action
			} // Closes all sword action
		} // Closes HUGE if statement
else noComprendo() ; 
		if (story == 0) {
			cout << ">> The dragon steps toward you, its head low.\n" ; }
		if (story == 1) {
			cout << ">> The dragon takes another step.\n" ; }
		if (story == 2) {
			cout << ">> Another step.  It's almost upon you now.\n" ; }
	} // Closes final battle loop story < 4
	while (area == 10) {
		cout << ">> Too late.  Looks like you couldn't avenge your father or save\nthe princess.\n>> Chomp.\n>> You have died.  Try again?  y/n: " ;
		cin >> action;
		if (action == "y" || action == "n") {
			area = 11;
			itemNum[0] = 4;
	if (action == "y") {
		retry = 1; }
	else {
		retry = 0;
		cout << ">> Thanks for playing!" ; }
		  }
else noComprendo();
	} // Closes area == 10 retry loop
} // Closes while area == 10 loop 553
} // Closes playthrough loop itemNum[0] != 4
	} // CLOSES RETRY LOOP OF ENTIRE GAME
	
	return 0;
} // CLOSES MAIN FUNCTION 135
