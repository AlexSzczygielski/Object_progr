#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include <chrono> // For measuring time
#include <fstream>
#include <sstream>

void print_map(const std::map<char,int>& m){
    for(auto& pair : m){
        //std::cout << "frequency of '" << pair.first << "' : " << pair.second << std::endl;
    }
}

void letter_frequency_map(const std::string& s){
    std::map<char,int> frequency_map; //map - keys strings and values integers
    
    for(int i = 0; i<s.size();i++){
        frequency_map[s[i]]++;
    }
    print_map(frequency_map);
}

void letter_frequency_sort(std::string& s){
    std::sort(s.begin(),s.end());
    //std::cout << s;
    char temp = s[0];
    int count = 0;
    for(int i = 0; i<=s.size();i++){
        //std::cout << s[i] << std::endl;
        if(s[i] == temp){ //here always at the 1st iteration
            count++;
        } else{
            //std::cout<< "frequency of '" << temp << "' : " << count << std::endl;
            temp = s[i];
            count = 1;
        }
    }
}

// Function to read content of a file into a string
std::string read_file_to_string(const std::string& file_path) {
    std::ifstream file(file_path); // Open file for reading
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << file_path << std::endl;
        return "";
    }

    std::ostringstream buffer;
    buffer << file.rdbuf(); // Read entire file into buffer
    return buffer.str();
}

int main(){
    std::string word;
    std::cout << "provide word to count frequency of repeating letters:\n";
    //std::cin >> word;
    /*word = "O Lithuania, my native land,"
"you are like health--so valued when lost beyond recovery; let these words now stand restoring you, redeeming exile's cost."
"Holy Virgin, defender of the Shrine"
"at Czestochowa, who illuminates 1 the Ostra Gate in Vilno, whose sign 2 revealed as one of her protectorates"
"the walled Novogrodek--who saved me once"
"with her miraculous glow. My tearful mother"
"entrusted me (it was her only chance,"
"I was near death) so when there was no other"
"cure, she helped to open up my eyes,"
"and once my lids were raised, though weak, I made"
"a pilgrimage to offer thanks and praise."
"This memory of resurrection has stayed"
"alive in me since childhood; it makes"
"me hope a homesick exile might return"
"to wooded hills, green meadows, and the lakes spread round the River Nieman--that I'd be borne back to that womb of gilded wheat and rye turned silver, to the amber mustard row, buckwheat snow, and clover, burning like a shy girl's blush--to strips of turf, ribbons that show boundaries with green. All this I see"
"so clearly, down to each blossoming pear tree."
"A larchwood manor stood upon the banks"
"of a stream, dividing groves of birch, its stone foundation propping up the solid ranks"
"6"
"of oak beams and whitewashed walls, which shone in stark relief against the darker green"
"of poplars all around. A barn attested"
"to abundant stores of grain, unseen,"
"and more in fields waiting to be harvested. Black earth, gridded from countless plows, fallow land, flowerbed, and garden-- everything about the farmstead shows"
"its owner's lot is prosperous. Even"
"stranger would face, like guest, a welcome sight, a gate, open by day, unlatched at night."
"A young man raced his carriage through the yard, halted his team by the porch and vaulted down. His horses dragged the coach, and panting hard, began to graze. The door was shut, the lawn deserted--anxiously he rushed to greet"
"inhabitant and house alike, unlatched"
"the lock, dismayed he found no one to meet."
"The youth was only recently dispatched"
"from a distant city where he'd gone to school."
"Now finished with his studies, he relearns"
"the old floor planks, eager to roam and rule"
"halls hung with tapestries. Now he returns"
"to find that nothing is unchanged. The halls"
"all seem less grand, perhaps a little quainter."
"The portraits he remembers still grace the walls:"
"Kosciuszko in Cracovian dress. (The painter 3 surely had in mind the time he swore,"
"clutching his sword, his eyes to heaven cast,"
"he'd drive the occupier from the door"
"of every Pole, or make this act his last.)"
"Rejtan was next, mourning his freedom's loss; 4 knife stuck in his own breast by his own hand,"
"(Plutarch's Life of Cato open across"
"his desk.) Next was Jasinski, his last stand: 5 the hero, young, handsome, and melancholy,"
"beside Korsak, comrades to the end. 6 (They stand in trenches aware of their huge folly:"
"dead Russians all around; they can't defend Warsaw--engulfed by flames from the attack.)"
"Tadeusz sees the antique chiming clock,"
"recalling how he'd tug a string in back;"
"repeating it provides a pleasing shock,"
"the same Mazurka of Dombrowski plays. 7"
"7"
"He scours the house, searching for the room,"
"ten years unseen, where he had spent the days"
"of childhood. But now he must assume"
"that all has changed, finding that change quite bold. What happened here? It seems someone rolled"
"a piano in, and songsheets--such disorder! Clearly female hands had made this mess: a hanger on the floor, a lace border-- half-draped upon a chair, an evening dress."
"Fragrant plants were lined up in a row:"
"geranium, carnation, aster, and violet."
"The young man spots new marvels down below: right by the stream, where once there was a thicket full of nettles, now a garden thrived,"
"criss-crossed by tiny paths, with clumps of mint and English grass. There was a fencepost carved with some initials, daisies and ribbons pinned"
"and marking it. The flowers were all slick"
"and wet; someone had sprinkled half the can"
"and left the garden, making such a quick"
"getaway, the gate still swung. Whoever ran"
"left shoeless footprints in the sand, though shallow, as if these feet had barely skimmed the ground."
"The traveler stood and mused beside the window, inhaling all the scents. In his profound confusion, he began to lean too far,"
"as if drawn to the garden and the path,"
"almost tumbling out. He began to stare"
"at something in the distance, taking his breath away--a girl dressed in white, her slight"
"body almost uncovered, shoulders and"
"a swan-like neck revealed! Such a sight"
"is rare in Lithuania, a land"
"where modesty prevails. And though she thought she was unseen, her arms were shyly crossed"
"to screen herself. Her hair was twisted taut"
"and wrapped around white paper strips--and lost, for now, the ringlets coiled and dangling free. And yet the rays of morning sunlight drowned her in such a strange embellished glow, she seemed to be a holy icon crowned."
"8"
"At first she searched for something in the meadow. He couldn't see her hidden face till she"
"began to run and skip. Thus he could follow";
*/
/*
    word = "aaaasasasasasasasasasasasasasasasasasasasasasasassasasasasasasasasasasa"
           "aaaasasasasasasasasasasasasasasasasasasasasasasassasasasasasasasasasasa"
           "aaaasasasasasasasasasasasasasasasasasasasasasasassasasasasasasasasasasa"
           "aaaasasasasasasasasasasasasasasasasasasasasasasassasasasasasasasasasasa"
           "aaaasasasasasasasasasasasasasasasasasasasasasasassasasasasasasasasasasa"
           "aaaasasasasasasasasasasasasasasasasasasasasasasassasasasasasasasasasasa"
           "aaaasasasasasasasasasasasasasasasasasasasasasasassasasasasasasasasasasa"
           "aaaasasasasasasasasasasasasasasasasasasasasasasassasasasasasasasasasasa"
           "aaaasasasasasasasasasasasasasasasasasasasasasasassasasasasasasasasasasa"
           "aaaasasasasasasasasasasasasasasasasasasasasasasassasasasasasasasasasasa"
           "aaaasasasasasasasasasasasasasasasasasasasasasasassasasasasasasasasasasa"
           "aaaasasasasasasasasasasasasasasasasasasasasasasassasasasasasasasasasasa"
           "aaaasasasasasasasasasasasasasasasasasasasasasasassasasasasasasasasasasa"
           "aaaasasasasasasasasasasasasasasasasasasasasasasassasasasasasasasasasasa"
           "aaaasasasasasasasasasasasasasasasasasasasasasasassasasasasasasasasasasa"
           "aaaasasasasasasasasasasasasasasasasasasasasasasassasasasasasasasasasasa"
           "aaaasasasasasasasasasasasasasasasasasasasasasasassasasasasasasasasasasa"
           "aaaasasasasasasasasasasasasasasasasasasasasasasassasasasasasasasasasasa"
           "aaaasasasasasasasasasasasasasasasasasasasasasasassasasasasasasasasasasa"
           "aaaasasasasasasasasasasasasasasasasasasasasasasassasasasasasasasasasasa"
           "aaaasasasasasasasasasasasasasasasasasasasasasasassasasasasasasasasasasa"
           "aaaasasasasasasasasasasasasasasasasasasasasasasassasasasasasasasasasasa"
           "aaaasasasasasasasasasasasasasasasasasasasasasasassasasasasasasasasasasa"
           "aaaasasasasasasasasasasasasasasasasasasasasasasassasasasasasasasasasasa"
           "aaaasasasasasasasasasasasasasasasasasasasasasasassasasasasasasasasasasa"
           "aaaasasasasasasasasasasasasasasasasasasasasasasassasasasasasasasasasasa";
           */
    
    std::string file_path = "mickiewicz.txt"; // Change this to the path of your file
    word = read_file_to_string(file_path);
    
    // Measure time for sort-based approach
    auto start_sort = std::chrono::high_resolution_clock::now();
    letter_frequency_sort(word);
    auto end_sort = std::chrono::high_resolution_clock::now();
    auto duration_sort = std::chrono::duration_cast<std::chrono::microseconds>(end_sort - start_sort);
    std::cout << "Time taken by sort-based approach: " << duration_sort.count() << " microseconds\n";

    // Measure time for map-based approach
    auto start_map = std::chrono::high_resolution_clock::now();
    letter_frequency_map(word);
    auto end_map = std::chrono::high_resolution_clock::now();
    auto duration_map = std::chrono::duration_cast<std::chrono::microseconds>(end_map - start_map);
    std::cout << "Time taken by map-based approach: " << duration_map.count() << " microseconds\n";

    return 0;
}