#include "printfd/HEADER/ft_printfd.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define MAX_TITLE 100

const char *positive_responses[] = {
    "Bravo, tu es un génie !",
    "Incroyable, tu as vraiment répondu correctement !",
    "Félicitations ! Tu devrais jouer à la loterie aujourd'hui !",
    "Wow, tu as vraiment réussi ça ? Je suis impressionné !",
    "Tu as dû tricher, non ? C'est trop bien pour être vrai !",
    "Einstein serait fier de toi !",
    "Tu es sur une lancée ! Continue comme ça !",
    "Les maths n'ont aucun secret pour toi, n'est-ce pas ?",
    "Tu viens de sauver l'univers avec cette réponse !",
    "Tu es le roi des multiplications !",
    "C'était trop facile pour toi, hein ?",
    "Quelle performance incroyable !",
    "Je vais devoir augmenter la difficulté, tu es trop bon !",
    "Je parie que tu pourrais résoudre ça les yeux fermés !",
    "Qui a besoin d'une calculatrice quand on a ton cerveau ?",
    "Tu es le Mozart des mathématiques !",
    "Tu viens de briser la barrière du son avec cette réponse !",
    "Les nombres te sont soumis !",
    "On dirait que tu as trouvé la clé de la matrice !",
    "Tu es un véritable sorcier des chiffres !",
    "Tu pourrais probablement résoudre des équations dans ton sommeil !",
    "La force est puissante en toi, jeune Padawan !",
    "Tu es une véritable légende des multiplications !",
    "C'est toi qui as écrit les tables de multiplication, non ?",
    "Tu viens de propulser les mathématiques dans une nouvelle ère !",
    "Tu as vaincu cette question avec brio !",
    "Les chiffres dansent devant tes yeux tel un ballet !",
    "Tu as trouvé la réponse comme si c'était une promenade dans le parc !",
    "Tu es un maître incontesté des mathématiques !",
    "Tu es l'élu, celui qui apportera l'équilibre aux nombres !",
	"Tu as décodé la formule secrète de la multiplication !",
    "Ça alors, tu es un véritable prodige des maths !",
    "Les nombres se courbent à ta volonté !",
    "Tu as dû être prof de maths dans une autre vie !",
    "Tu fais des calculs aussi vite qu'un superordinateur !",
    "Ta réponse était tellement brillante qu'elle a illuminé la pièce !",
    "Les génies des maths sont verts de jalousie !",
    "Tu as trouvé la réponse comme si tu avais un sixième sens !",
    "La prochaine fois, je te poserai des questions plus difficiles, champion !",
    "C'était tellement impressionnant que j'en suis resté bouche bée !",
    "Les mathématiciens célèbres applaudissent ta réussite !",
    "Tu as fait des calculs si rapides que j'ai cru voir une étoile filante !",
    "Je suis sûr que tu as un super-héros mathématique caché en toi !",
    "Tu as résolu cette question comme un chef !",
    "Les anges des maths chantent tes louanges !",
    "Tu es le héros dont les nombres ont toujours rêvé !",
    "Les chiffres se plient à ta volonté comme des origamis !",
    "Tu as résolu cette question avec la précision d'un chirurgien !",
    "Les maths sont ton royaume et tu en es le souverain !",
    "Tu as trouvé la réponse aussi facilement qu'un ninja des maths !",
	"Tu as réussi cette multiplication avec brio, comme un virtuose du piano !",
    "Félicitations, tu es l'as des multiplications !",
    "Bravo, tu viens de marquer un but dans le match des maths !",
    "On dirait que tu as un doctorat en multiplications !",
    "Tu as trouvé la réponse avec la grâce d'un danseur étoile !",
    "Félicitations, tu es un véritable artiste des chiffres !",
    "Tu es le roi ou la reine des multiplications !",
    "Bravo, tu viens de décrocher la médaille d'or des maths !",
    "Ta réponse est aussi délicieuse qu'un gâteau tout juste sorti du four !",
    "Félicitations, tu as trouvé la réponse avec l'élégance d'un papillon !",
    "Ton talent pour les multiplications est digne d'un prix Nobel !",
    "Bravo, tu as trouvé la réponse comme un détective résolvant une enquête !",
    "Félicitations, ta réponse est un chef-d'œuvre des maths !",
    "Tu as réussi cette multiplication avec la précision d'un horloger !",
    "Ton succès en maths est aussi éclatant qu'un feu d'artifice !",
    "Bravo, tu as résolu cette multiplication comme un maître du Rubik's Cube !",
    "Félicitations, tu es l'explorateur qui a découvert le trésor caché des maths !",
    "Tu as trouvé la réponse comme un plongeur trouvant une perle rare !",
    "Ton talent pour les multiplications est aussi impressionnant qu'un acrobate !",
    "Félicitations, tu as résolu cette multiplication avec la force d'un champion !",
    "Bravo, tu as trouvé la réponse avec la finesse d'un escrimeur !",
    "Félicitations, ta réussite en maths est aussi étonnante qu'un magicien !",
    "Ton succès en maths est aussi impressionnant qu'un échec et mat !",
    "Bravo, tu as dompté cette multiplication comme un dresseur de lions !",
    "Félicitations, tu as trouvé la réponse avec la perspicacité d'un philosophe !",
    "Bravo, tu viens de franchir la ligne d'arrivée des maths !",
    "Félicitations, ta réponse est aussi rafraîchissante qu'une cascade !",
    "Ton succès en maths est aussi éblouissant qu'un arc-en-ciel !",
    "Bravo, tu as réussi cette multiplication comme un alpiniste atteignant le sommet !",
    "Félicitations, ta réussite en maths est aussi majestueuse qu'un paon !",
	"Tu as utilisé la Force pour trouver cette réponse, jeune Jedi !",
    "Félicitations, tu es le Sherlock Holmes des multiplications !",
    "Wakanda forever ! Les ancêtres seraient fiers de ta réussite.",
    "C'est un grand pas pour l'humanité, et un petit pas pour les maths !",
    "Aussi rapide que Flash, tu as trouvé la bonne réponse !",
    "Wow, tu viens de réussir un combo parfait comme dans Street Fighter !",
    "Ton talent pour les maths est... sans pareil, comme dans Matrix !",
    "Les Avengers pourraient t'embaucher pour tes compétences en maths !",
    "Félicitations, tu viens de remporter la Coupe des maths à Poudlard !",
    "Ça alors, tu es le One Punch Man des multiplications !",
    "Tel un Saiyan, ta puissance mathématique est impressionnante !",
    "Le TARDIS n'a pas eu besoin de t'aider pour cette réponse !",
    "La bonne réponse vient d'être dévoilée, comme un tour de magie de Gandalf !",
    "Tu as trouvé la réponse aussi facilement que si tu avais utilisé un Poké Ball !",
    "Les tributs des maths te félicitent pour ta victoire, tu as survécu à l'arène !",
    "En un éclair, tu as résolu cette multiplication comme Barry Allen !",
    "Ça y est, tu as déchiffré les codes secrets des maths comme Alan Turing !",
    "Tu as résolu cette multiplication avec autant de succès que Tony Stark construisant une armure !",
    "Les Vulcains salueraient ta logique implacable !",
    "Le Génie d'Aladdin t'offrirait un vœu pour cette réussite !",
    "Tu as réussi cette multiplication avec la précision d'un maître Pokémon !",
    "Félicitations, tu as trouvé la réponse comme si tu avais déchiffré les hiéroglyphes égyptiens !",
    "Ton talent pour les maths est digne d'un Jedi maîtrisant la Force !",
    "Même le Docteur Strange n'aurait pas trouvé une meilleure réponse !",
    "Tu as résolu cette multiplication comme Neo esquivant des balles dans Matrix !",
    "C'est un succès digne de la victoire de Rocky Balboa !",
    "Bien joué, tu viens de sauver le monde des maths comme les Ghostbusters !",
    "Tu es le héros des maths que Gotham mérite !",
    "Ton talent mathématique rivalise avec celui de Sherlock Holmes !",
    "Grâce à toi, les maths viennent de prendre leur envol comme Superman !",
	"Bravo, tu as réussi cette multiplication comme un super-héros sauvant la journée !",
    "Félicitations, tu es le maître Jedi des multiplications !",
    "Ta réponse est aussi impressionnante que les exploits de Sherlock Holmes !",
    "Ton succès en maths est aussi brillant que la Bat-Signal dans le ciel nocturne !",
    "Bravo, tu as trouvé la réponse comme Indiana Jones découvrant un trésor perdu !",
    "Félicitations, tu as réussi cette multiplication comme un Saiyan survolant le combat !",
    "Tu es le héros des maths dont Gotham a besoin !",
    "Bravo, tu as maîtrisé cette multiplication comme Yoda maîtrise la Force !",
    "Félicitations, tu as trouvé la réponse comme Neo esquivant des balles dans Matrix !",
    "Ta réponse est aussi percutante que le Mjölnir de Thor !",
    "Bravo, tu as réussi cette multiplication comme Iron Man en plein vol !",
    "Félicitations, tu as résolu cette multiplication comme les Avengers sauvant le monde !",
    "Ton succès en maths est aussi impressionnant que les exploits de Naruto !",
    "Bravo, tu as réussi cette multiplication comme Captain America lançant son bouclier !",
    "Félicitations, tu as vaincu cette multiplication comme Goku vainquant ses ennemis !",
    "Ta réponse est aussi étonnante que les pouvoirs de Doctor Strange !",
    "Bravo, tu as réussi cette multiplication comme Wonder Woman repoussant les balles !",
    "Félicitations, tu as résolu cette multiplication comme Harry Potter lançant un sort !",
    "Ton succès en maths est aussi remarquable que les aventures de Tintin !",
    "Bravo, tu as réussi cette multiplication comme un Pokémon maîtrisant son attaque !",
    "Félicitations, tu as triomphé de cette multiplication comme Simba devenant roi !",
    "Ta réponse est aussi impressionnante que le parcours de Frodon en Terre du Milieu !",
    "Bravo, tu as réussi cette multiplication comme Spider-Man tissant sa toile !",
    "Félicitations, tu as trouvé la réponse comme les X-Men luttant pour la justice !",
    "Ton succès en maths est aussi puissant que le coup de poing de One Punch Man !",
    "Bravo, tu as réussi cette multiplication comme un Titan dévorant ses adversaires !",
    "Félicitations, tu as résolu cette multiplication comme les agents du S.H.I.E.L.D. résolvant un mystère !",
    "Ta réponse est aussi étonnante que l'arrivée de Marty McFly dans le futur !",
    "Bravo, tu as réussi cette multiplication comme Sailor Moon protégeant la Terre !",
    "Félicitations, tu as trouvé la réponse comme les Ghostbusters attrapant des fantômes !"
};

const char *negative_responses[] = {
    "Oh non, c'est complètement faux !",
    "Tu as dû confondre avec une autre opération.",
    "Ça, c'est un échec spectaculaire !",
    "Yikes! Tu étais tellement proche... enfin, pas vraiment.",
    "Ne t'inquiète pas, les maths, ce n'est pas pour tout le monde...",
    "On dirait que quelqu'un a besoin de revoir ses tables de multiplication !",
    "Essaie encore, je suis sûr que tu peux faire mieux !",
    "Oups, ça n'a pas marché cette fois-ci.",
    "Tu ferais mieux d'appeler un ami pour t'aider !",
    "Ça arrive même aux meilleurs, ne t'inquiète pas !",
    "Qui a éteint les lumières ? Ta réponse était dans l'obscurité !",
    "Tu as frôlé la bonne réponse... dans une autre dimension !",
    "Peut-être que tu devrais essayer de lancer une pièce la prochaine fois ?",
    "La prochaine fois, essaie de ne pas diviser en résolvant une multiplication !",
    "Ne désespère pas, l'échec est la première étape vers le succès !",
    "On dirait que les chiffres t'ont joué un tour pendable !",
    "Si seulement tu pouvais utiliser un joker !",
    "Tu pourrais peut-être demander à Siri ou Google Assistant la prochaine fois ?",
    "Les extraterrestres doivent rire de cette réponse en ce moment !",
    "Oops! Ta réponse vient de glisser sur une peau de banane !",
    "Tu as été victime du monstre des chiffres !",
    "C'est un désastre mathématique !",
    "On dirait que tu as trébuché sur cette question !",
    "Ta réponse s'est perdue dans le triangle des Bermudes des maths !",
    "Même un poisson ferait mieux que ça !",
    "Ça a dû être un coup de vent qui t'a fait rater cette réponse !",
    "Quelqu'un a dû saboter ta calculatrice !",
    "On dirait que les chiffres se sont rebellés contre toi !",
    "Peut-être que tu devrais essayer de négocier avec les nombres la prochaine fois ?",
    "Aïe ! Ta réponse vient de s'écraser contre un mur !",
	"Les maths t'ont posé un lapin cette fois-ci !",
    "On dirait que ta réponse a été avalée par un trou noir !",
    "Ta réponse est tellement fausse qu'elle en est presque comique !",
    "C'est le moment où l'on souhaite avoir une machine à remonter le temps !",
    "Les fantômes des mathématiciens célèbres viennent de pousser un soupir !",
    "Essaie de ne pas trop t'égarer dans la forêt des erreurs la prochaine fois !",
    "Ta réponse est passée à côté de la plaque comme un OVNI !",
    "Même les pierres sont meilleures en maths que ça !",
    "Ta réponse a dû être écrite avec un stylo invisible !",
    "Les chiffres se sont cachés pour rire de ta réponse !",
    "Ta réponse est tellement à côté de la réalité qu'elle pourrait être dans un film de science-fiction !",
    "Peut-être que tu devrais appeler les pompiers pour éteindre ce désastre mathématique !",
    "C'est un naufrage mathématique !",
    "Les chiffres sont partis en courant en voyant ta réponse !",
    "On dirait que tu as été victime d'une invasion de chiffres extraterrestres !",
    "Si seulement les erreurs étaient des trésors, tu serais riche !",
    "Tu as malheureusement déterré la réponse du cimetière des erreurs !",
    "Essaie de ne pas tomber dans le piège des fausses réponses la prochaine fois !",
    "Ta réponse s'est égarée dans le labyrinthe des erreurs !",
    "Tu as trouvé une perle rare... de fausseté !",
    "Les chiffres ont organisé une révolution contre ta réponse !",
    "Ta réponse est comme un mirage dans le désert des maths !",
    "On dirait que les nombres ont fait des farces sur ta réponse !",
    "C'est un flop mathématique retentissant !",
    "Les maths ont décidé de te jouer un mauvais tour cette fois-ci !",
    "Peut-être que les chiffres se sont déguisés pour te tromper !",
    "Il doit y avoir un complot contre toi dans le monde des maths !",
    "Les chiffres ont décidé de prendre des vacances pendant que tu répondais !",
    "On dirait que tu as été victime d'un tour de magie raté !",
    "Ta réponse a pris un ticket pour le train des erreurs !",
	"Oh non, tu as raté cette multiplication comme un acteur oubliant son texte !",
    "On dirait que les chiffres t'ont échappé comme un poisson hors de l'eau !",
    "Ta réponse est passée à côté de la plaque comme un joueur de fléchettes !",
    "Les maths ont été aussi insaisissables que le vent cette fois",
	"Il semble que tu te sois perdu dans le labyrinthe des multiplications !",
    "On dirait que ta réponse a été piégée dans une toile d'araignée d'erreurs !",
    "Ta réponse a glissé comme un patineur sur une plaque de verglas !",
    "Les chiffres ont pris la tangente comme un funambule sans filet !",
    "On dirait que tu as trébuché sur les marches de l'escalier des maths !",
    "Ta réponse est passée à côté du but comme un penalty raté !",
    "Les maths ont été aussi fuyantes qu'un chat effrayé cette fois-ci !",
    "Ta réponse a coulé comme un bateau en plein naufrage !",
    "On dirait que tu as été pris dans les filets de la confusion !",
    "Les chiffres se sont envolés comme des oiseaux effarouchés !",
    "Ta réponse a été aussi imprécise qu'un horoscope !",
    "Les maths ont été aussi insaisissables qu'un rêve au réveil !",
    "On dirait que tu as été pris au piège des erreurs comme un rat dans une souricière !",
    "Les chiffres ont été aussi capricieux qu'une météo changeante !",
    "Ta réponse s'est évaporée comme une goutte d'eau au soleil !",
    "Les maths ont pris la fuite comme un voleur dans la nuit !",
    "Ta réponse est passée à côté de la cible comme une flèche sans pointe !",
    "On dirait que ta réponse a sombré dans l'océan des erreurs !",
    "Ta réponse a été soufflée comme un château de cartes !",
    "Les chiffres ont été aussi insaisissables qu'un mirage dans le désert !",
	"Oh non, les maths t'ont échappé comme Harry Potter sur son balai !",
    "Les maths ont joué un tour à ta réponse comme Gollum et son précieux !",
    "Tu as raté cette multiplication comme Anakin Skywalker a raté le test des Jedi !",
    "Cette réponse était presque aussi décevante que la fin de Game of Thrones !",
	"Ta réponse est passée à côté comme un Stormtrooper qui tire !",
    "On dirait que cette multiplication a été aussi difficile à résoudre que le mystère de la Chambre des Secrets !",
    "Ton erreur est aussi visible que le nez au milieu de la figure de Voldemort !",
    "Les maths ont été aussi insaisissables que le One Ring pour Frodon !",
    "Tu as fait un faux pas dans cette multiplication comme Peter Parker avant de devenir Spider-Man !",
    "Cette erreur te fait ressembler à C-3PO sans ses circuits de logique !",
    "Ton erreur est aussi étonnante que l'apparition d'un fantôme dans Scooby-Doo !",
    "Les chiffres ont été aussi trompeurs que Loki pour cette réponse !",
    "On dirait que tu as été ensorcelé par Maleficent et que tu as raté cette multiplication !",
    "Ta réponse est aussi confuse que le Minotaure dans le labyrinthe !",
    "Ta réponse est aussi éloignée que la galaxie d'Andromède !",
    "Les maths ont été aussi furtives que Batman dans la nuit !",
    "Cette erreur te fait ressembler à un Moldu essayant de faire de la magie !",
    "Tu as raté cette multiplication comme Marty McFly essayant de réparer la machine à remonter le temps !",
    "Ton erreur est aussi surprenante qu'une attaque de zombies dans The Walking Dead !",
    "Les chiffres ont été aussi insaisissables que les Pokémon légendaires !",
    "On dirait que tu as été piégé par Jigsaw et que tu as raté cette multiplication !",
    "Cette erreur est aussi étrange que les événements dans Stranger Things !",
    "Les maths ont été aussi mystérieuses que l'identité de l'assassin dans un roman d'Agatha Christie !",
    "Ton erreur est aussi marquante que le cri de Tarzan dans la jungle !",
	"Oh non, les maths t'ont échappé comme Harry Potter sur son balai !",
    "Les maths ont joué un tour à ta réponse comme Gollum et son précieux !",
	"Tu as raté cette multiplication comme Anakin Skywalker a raté le test des Jedi !",
    "Cette réponse était presque aussi décevante que la fin de Game of Thrones !",
    "On dirait que tu as trébuché sur cette multiplication comme Bella Swan devant Edward Cullen !",
    "Ta réponse est aussi erronée que l'orientation de Zoro dans One Piece !",
    "Les maths t'ont échappé comme le Tesseract à l'Agent Coulson !",
    "On dirait que tu as été berné par cette multiplication comme Simba par Scar !",
    "Les maths ont été aussi insaisissables que les Détraqueurs de Harry Potter !",
    "Ta réponse est aussi éloignée que la distance entre la Terre et Krypton !",
    "Tu as raté cette multiplication comme Aquaman essayant de respirer hors de l'eau !",
    "Ton erreur ressemble à une mauvaise potion concoctée par le Dr Jekyll !",
    "Les chiffres ont été aussi capricieux que le Joker pour cette réponse !",
    "On dirait que cette multiplication t'a piégé comme les Hunger Games !",
    "Ta réponse est aussi éloignée que la planète natale d'E.T. !",
    "Les maths ont été aussi déroutantes que les voyages temporels dans Doctor Who !",
    "Ta réponse est aussi confuse que la relation entre Edward et Bella dans Twilight !",
    "Les maths ont été aussi insaisissables que les pierres d'infinité pour Thanos !",
    "On dirait que cette multiplication t'a échappé comme le Génie de la lampe d'Aladdin !",
    "Ton erreur est aussi surprenante que la révélation de l'identité de Darth Vader !",
    "Les chiffres ont été aussi trompeurs que les illusions de Mysterio !",
    "On dirait que cette multiplication t'a échappé comme le TARDIS dans Doctor Who !"
};

typedef struct {
    int num1;
    int num2;
    int answer;
    bool correct;
} Question;

void print_title(void)
{
    printf("\n\033[1;36m _____ ______   ___  ___  ___   _________  ___          ________  ___  ___  ___  ________  ________\n");
    printf("|\\   _ \\  _   \\|\\  \\|\\  \\|\\  \\ |\\___   ___\\\\  \\        |\\   __  \\|\\  \\|\\  \\|\\  \\|\\_____  \\|\\_____  \\    \n");
    printf("\\ \\  \\\\\\__\\ \\  \\ \\  \\\\\\  \\ \\  \\\\|___ \\  \\_\\ \\  \\       \\ \\  \\|\\  \\ \\  \\\\\\  \\ \\  \\\\|___/  /|\\|___/  /|   \n");
    printf(" \\ \\  \\\\|__| \\  \\ \\  \\\\\\  \\ \\  \\    \\ \\  \\ \\ \\  \\       \\ \\  \\\\\\  \\ \\  \\\\\\  \\ \\  \\   /  / /    /  / /   \n");
    printf("  \\ \\  \\    \\ \\  \\ \\  \\\\\\  \\ \\  \\____\\ \\  \\ \\ \\  \\       \\ \\  \\\\\\  \\ \\  \\\\\\  \\ \\  \\ /  /_/__  /  /_/__  \n");
    printf("   \\ \\__\\    \\ \\__\\ \\_______\\ \\_______\\ \\__\\ \\ \\__\\       \\ \\_____  \\ \\_______\\ \\__\\\\________\\\\________\\\n");
    printf("    \\|__|     \\|__|\\|_______|\\|_______|\\|__|  \\|__|        \\|___| \\__\\|_______|\\|__|\\|_______|\\|_______|\n");
    printf("                                                                 \\|__|                                  \n\033[0m");
	ft_printfd(1, "\n#0#/b                 #_Le code ainsi que les réponses de ce quizz ont ete generer pas chatGPT-4#0\n\n");
}

void shuffle_responses(const char **responses, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        const char *temp = responses[i];
        responses[i] = responses[j];
        responses[j] = temp;
    }
}

void shuffle_questions(Question *questions, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Question temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }
}

int quizz(int max_number, int questions_count) {
    srand(time(NULL));

	print_title();

	int score = 0;
	Question questions[questions_count];
	size_t positive_responses_count = sizeof(positive_responses) / sizeof(positive_responses[0]);
	size_t negative_responses_count = sizeof(negative_responses) / sizeof(negative_responses[0]);

	const char *shuffled_positive_responses[positive_responses_count];
	const char *shuffled_negative_responses[negative_responses_count];

	memcpy(shuffled_positive_responses, positive_responses, sizeof(positive_responses));
	memcpy(shuffled_negative_responses, negative_responses, sizeof(negative_responses));

	shuffle_responses(shuffled_positive_responses, positive_responses_count);
	shuffle_responses(shuffled_negative_responses, negative_responses_count);

	size_t positive_response_index = 0;
	size_t negative_response_index = 0;

	for (int i = 0; i < questions_count; i++) {
	    int num1, num2;
	    bool unique = false;
	    while (!unique) {
	        unique = true;
	        num1 = (rand() % (max_number - 1)) + 2;
	        num2 = (rand() % (max_number - 1)) + 2;
	        for (int j = 0; j < i; j++) {
	            if (questions[j].num1 == num1 && questions[j].num2 == num2) {
	                unique = false;
	                break;
	            }
	        }
	    }
	    questions[i].num1 = num1;
	    questions[i].num2 = num2;
	}

	shuffle_questions(questions, questions_count);

	printf("\n\033[1;33mJeux des tables de multiplication jusqu'à %d\033[0m\n", max_number);
	ft_printfd(1, "\n#/pVous avez %d questions à répondre. Bonne chance !#0\n\n", questions_count);

	for (int i = 0; i < questions_count; i++) {
	    int user_answer;

	    printf("\033[1;34mQuestion %d sur %d :\n\033[1;33m%d x %d = \033[0m", i + 1, questions_count, questions[i].num1, questions[i].num2);
	    if (scanf("%d", &user_answer) != 1) {
	        printf("\033[1;31mErreur de saisie. Veuillez entrer un nombre entier.\033[0m\n");
	        return 1;
	    }

	    questions[i].answer = questions[i].num1 * questions[i].num2;
	    questions[i].correct = user_answer == questions[i].answer;

	    if (questions[i].correct) {
	        printf("\033[1;32m%s\033[0m\n\n", shuffled_positive_responses[positive_response_index]);
	        score++;
	        positive_response_index++;
	        if (positive_response_index == positive_responses_count) {
	            positive_response_index = 0;
	            shuffle_responses(shuffled_positive_responses, positive_responses_count);
	        }
	    } else {
	        printf("\033[1;31m%s La réponse correcte était %d.\033[0m\n\n", shuffled_negative_responses[negative_response_index], questions[i].answer);
	        negative_response_index++;
	        if (negative_response_index == negative_responses_count) {
				negative_response_index = 0;
				shuffle_responses(shuffled_negative_responses, negative_responses_count);
			}
		}
	}
	printf("\033[1;35mTableau récapitulatif :\033[0m\n\n");
	printf("\033[1;34m%-10s %-10s %-10s %-10s\033[0m\n\n", "Question", "No. 1", "No. 2", "Réponse");
	for (int i = 0; i < questions_count; i++) {
	    printf("%-10d %-10d %-10d %-10d ", i + 1, questions[i].num1, questions[i].num2, questions[i].answer);
	    if (questions[i].correct) {
	        printf("\033[1;32mCorrect\033[0m\n");
	    } else {
	        printf("\033[1;31mIncorrect\033[0m\n");
	    }
	}

	printf("\nVotre score: \033[1;35m%d\033[0m sur \033[1;35m%d\033[0m questions.\n\n", score, questions_count);

	return 0;
}

void	first_line(int n)
{
	ft_printfd(1, "#y%4d #g", 1);
	for (int i = 2; i <= n; i++)
	{
		ft_printfd(1, "%4d ", i);
	}
	if (n > 1)
		ft_printfd(1, "#y   1#0\n");
	else
		ft_printfd(1, "#0\n");
}

void	line(int n, int j)
{
	ft_printfd(1, "#b%4d #0", j);
	for (int i = 2; i <= n; i++)
	{
		if (i == j)
			ft_printfd(1, "#r%4d ", i * j);
		else if (i == j - 1 || i == j + 1)
			ft_printfd(1, "#p%4d ", i * j);
		else if (!((i + j) % 2))
			ft_printfd(1, "#y%4d ", i * j);
		else
			ft_printfd(1, "#0%4d ", i * j);
	}
	ft_printfd(1, "#b%4d#0\n", j);
}

void	cut_line(int n)
{
	ft_printfd(1, "#y%5c", ' ');
	for (int i = 1; i < n; i++)
	{
		ft_printfd(1, "%4s ", "---");
	}
	ft_printfd(1, "#0\n");
}

void xy_tab(int n)
{
	ft_printfd(1, "\n");
	first_line(n);
	ft_printfd(1, "\n");
	//cut_line(n);
	for (int i = 2; i <= n; i++)
	{
		line(n, i);
		ft_printfd(1, "\n");
		//cut_line(n);
	}
	if (n > 1)
	{
		first_line(n);
		ft_printfd(1, "\n");
	}
}

void range_tab(int n, int min, int max, int columns)
{
	int i;
	int j;
	int min_b = min;
	int check = 1;
	while (check)
	{
		i = 0;
		ft_printfd(1, "\n");
		while (i < 10)
		{
			j = 0;
			while (j++ < columns)
			{
				if (min_b <= max)
					ft_printfd(1, "#b%4d#y x#b %-5d#y= #g%-7d ", min_b, n, min_b * n);
				if (min_b >= max)
				{
					check = 0;
					break;
				}
				min_b += 10;
			}
			ft_printfd(1, "\n");
			if (min >= max)
				break;
			min++;
			min_b = min;
			i++;
		}
		min += (columns - 1) * 10;
		min_b = min;
	ft_printfd(1, "\n#0");
	}
}

void print_usage(void)
{
	ft_printfd(1, "\n#+_yUSAGE#0#y :\n\n#0#g1 argument :#/g [ multi $A ]\n#/b  \"Affiche un tableau de $A * $A avec dans chaques cases le produit de l'axe x et y\"\n\n#0#g2 arguments :#/g [ multi $A $B ]\n#/b  \"Affiche la table de multiplication de $A de 1 * $A a $B * $A\"\n\n#0#g3 arguments :#/g [ multi $A $B $C ]\n#/b  \"Affiche la table de multiplication de $A de $B(valeur min) * $A a $C(valeur max) * $A\"\n\n#0#g4 arguments :#/g [ multi $A $B $C $D ]\n#/b  \"Affiche la table de multiplication de $A de $B(valeur min) * $A a $C(valeur max) * $A sur $D colonnes max (comportement naturel : 3 colonnes)\"\n\n#0#gOption -q et un seul argument :#/g [ multi -q $A ]\n#/b  \"Quizz de multiplication avec 10 questions jusqu'a $A x $A\"\n\n#0#gOption -q plus 2 arguments :#/g [ multi -q $A $B ]\n#/b  \"Quizz de multiplication avec $B questions jusqu'a $A x $A\"\n\n");
}

int	return_error(char *s)
{
	ft_printfd(2, "\n#+rERROR : [#/ !!! %s !!!#0#+r ]#0\n", s);
	print_usage();
	return (1);
}

int	arg_check(const char *s)
{
	if (*s == '-')
	{
		while (*s == '-')
			++s;
		if (*s == 'q')
		{
			while (*s == 'q')
				++s;
			if (!*s)
				return (1);
			else
				return (0);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		print_usage();
		return (0);
	}

	int n;
	int nb;
	int nc;

	if (arg_check(av[1]))
	{
		if (ac < 3)
			return (return_error("Pas assez d'arguments"));
		n = atoi(av[2]);
		if (n < 2)
			return (return_error("Argument invalide, le 2eme argument doit etre un chiffre/nombre superieur a 1, tu ne vas pas repeter les tables de 1 ou de moins 1 ?"));
		if (ac > 3)
		{
			nb = atoi(av[3]);
			if (nb < 1)
				return (return_error("Argument invalide, le 3eme argument doit etre un chiffre/nombre superieur a 0, tu veux repondre a au moins une question ?"));
			return (quizz(n, nb));
		} else
			return (quizz(n, 10));
	}

	n = atoi(av[1]);

	if (n < 1)
		return (return_error("Argument invalide, le 1er argument n'est pas un chiffre ou un nombre positif"));

	if (ac < 3)
	{
		if (n > 50)
			return (return_error("Argument invalide, ce nombre est trop grand"));
		xy_tab(n);
	}
	else
	{
		nb = atoi(av[2]);
		if (nb < 1)
			return (return_error("Argument invalide, le 2eme argument n'est pas un chiffre ou un nombre positif"));
		if (ac > 3)
		{
			nc = atoi(av[3]);
			if (nc < 1)
				return (return_error("Argument invalide, le 3eme argument n'est pas un chiffre ou un nombre positif"));
			else if (nb > nc)
				return (return_error("Argument invalide, la valeur min ne peux pas etre superieur a la valeur max"));
			if (ac > 4)
			{
				int column_max = atoi(av[4]);
				if (column_max < 1)
					return (return_error("Argument invalide, le 4eme argument n'est pas un chiffre ou un nombre positif"));
				range_tab(n, nb, nc, column_max);
			} else
				range_tab(n, nb, nc, 4);
		} else
			range_tab(n, 1, nb, 4);
	}


	return (0);
}