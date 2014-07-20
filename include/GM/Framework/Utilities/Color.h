#pragma once

// Disclaimer: Based on clanDisplay's color class

#include <glm/vec4.hpp>
#include <vector>

namespace GM {
	namespace Framework {

class PixelFormat;
class Colorf;

class Color : public glm::vec4
{

public:
	Color() {}

	explicit Color(const Colorf&);

	Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255)
		: glm::vec4(red, green, blue, alpha) { return; }

	// Color components are specified in the range 0 to 255.\n
	// An alpha value of 0 means complete transparency, while 255 means completely opaque (solid).
	// The colors rgba components as a hexadecimal string of the format "#rrggbbaa", where the '#' and "aa" parts are optional.
	Color(const std::string &hexstr);

	// Range 0 - 255
	unsigned char get_alpha() const { return a; }
	unsigned char get_red() const { return r; }
	unsigned char get_green() const { return g; }
	unsigned char get_blue() const { return b; }

	// Range 0.0 - 1.0
	float get_alpha_f() const { return float(a) / 255.0f; }
	float get_red_f() const { return float(r) / 255.0f; }
	float get_green_f() const { return float(g) / 255.0f; }
	float get_blue_f() const { return float(b) / 255.0f; }

	// ARGB8888 format.
	unsigned int get_argb8() const { return (((unsigned int)a) << 24) | (((unsigned int)r) << 16) | (((unsigned int)g) << 8) | (unsigned int)b; }

	// ABGR8888 format.
	unsigned int get_abgr8() const { return (((unsigned int)a) << 24) | (((unsigned int)b) << 16) | (((unsigned int)g) << 8) | (unsigned int)r; }

	// RGBA8888 format.
	unsigned int get_rgba8() const { return (((unsigned int)r) << 24) | (((unsigned int)g) << 16) | (((unsigned int)b) << 8) | (unsigned int)a; }

	// BGRA8888 format.
	unsigned int get_bgra8() const { return (((unsigned int)b) << 24) | (((unsigned int)g) << 16) | (((unsigned int)r) << 8) | (unsigned int)a; }

	std::string get_rgb8_hexstring() const;
	std::string get_rgba8_hexstring() const;

	bool operator==(const Color &c) const
	{
		return (r == c.r) && (g == c.g) && (b == c.b) && (a == c.a);
	}

	bool operator!=(const Color &c) const
	{
		return (r != c.r) || (g != c.g) || (b != c.b) || (a != c.a);
	}

	/// \brief <img src="../../img/colors/aliceblue-chip.png" width=16 height=16 > rgb(240, 248, 255).
	static Color aliceblue;

	/// \brief <img src="../../img/colors/antiquewhite-chip.png" width=16 height=16 > rgb(250, 235, 215).
	static Color antiquewhite;

	/// \brief <img src="../../img/colors/aqua-chip.png" width=16 height=16 > rgb( 0, 255, 255).
	static Color aqua;

	/// \brief <img src="../../img/colors/aquamarine-chip.png" width=16 height=16 > rgb(127, 255, 212).
	static Color aquamarine;

	/// \brief <img src="../../img/colors/azure-chip.png" width=16 height=16 > rgb(240, 255, 255).
	static Color azure;

	/// \brief <img src="../../img/colors/beige-chip.png" width=16 height=16 > rgb(245, 245, 220).
	static Color beige;

	/// \brief <img src="../../img/colors/bisque-chip.png" width=16 height=16 > rgb(255, 228, 196).
	static Color bisque;

	/// \brief <img src="../../img/colors/black-chip.png" width=16 height=16 > rgb( 0, 0, 0).
	static Color black;

	/// \brief <img src="../../img/colors/blanchedalmond-chip.png" width=16 height=16 > rgb(255, 235, 205).
	static Color blanchedalmond;

	/// \brief <img src="../../img/colors/blue-chip.png" width=16 height=16 > rgb( 0, 0, 255).
	static Color blue;

	/// \brief <img src="../../img/colors/blueviolet-chip.png" width=16 height=16 > rgb(138, 43, 226).
	static Color blueviolet;

	/// \brief <img src="../../img/colors/brown-chip.png" width=16 height=16 > rgb(165, 42, 42).
	static Color brown;

	/// \brief <img src="../../img/colors/burlywood-chip.png" width=16 height=16 > rgb(222, 184, 135).
	static Color burlywood;

	/// \brief <img src="../../img/colors/cadetblue-chip.png" width=16 height=16 > rgb( 95, 158, 160).
	static Color cadetblue;

	/// \brief <img src="../../img/colors/chartreuse-chip.png" width=16 height=16 > rgb(127, 255, 0).
	static Color chartreuse;

	/// \brief <img src="../../img/colors/chocolate-chip.png" width=16 height=16 > rgb(210, 105, 30).
	static Color chocolate;

	/// \brief <img src="../../img/colors/coral-chip.png" width=16 height=16 > rgb(255, 127, 80).
	static Color coral;

	/// \brief <img src="../../img/colors/cornflowerblue-chip.png" width=16 height=16 > rgb(100, 149, 237).
	static Color cornflowerblue;

	/// \brief <img src="../../img/colors/cornsilk-chip.png" width=16 height=16 > rgb(255, 248, 220).
	static Color cornsilk;

	/// \brief <img src="../../img/colors/crimson-chip.png" width=16 height=16 > rgb(220, 20, 60).
	static Color crimson;

	/// \brief <img src="../../img/colors/cyan-chip.png" width=16 height=16 > rgb( 0, 255, 255).
	static Color cyan;

	/// \brief <img src="../../img/colors/darkblue-chip.png" width=16 height=16 > rgb( 0, 0, 139).
	static Color darkblue;

	/// \brief <img src="../../img/colors/darkcyan-chip.png" width=16 height=16 > rgb( 0, 139, 139).
	static Color darkcyan;

	/// \brief <img src="../../img/colors/darkgoldenrod-chip.png" width=16 height=16 > rgb(184, 134, 11).
	static Color darkgoldenrod;

	/// \brief <img src="../../img/colors/darkgray-chip.png" width=16 height=16 > rgb(169, 169, 169).
	static Color darkgray;

	/// \brief <img src="../../img/colors/darkgreen-chip.png" width=16 height=16 > rgb( 0, 100, 0).
	static Color darkgreen;

	/// \brief <img src="../../img/colors/darkgrey-chip.png" width=16 height=16 > rgb(169, 169, 169).
	static Color darkgrey;

	/// \brief <img src="../../img/colors/darkkhaki-chip.png" width=16 height=16 > rgb(189, 183, 107).
	static Color darkkhaki;

	/// \brief <img src="../../img/colors/darkmagenta-chip.png" width=16 height=16 > rgb(139, 0, 139).
	static Color darkmagenta;

	/// \brief <img src="../../img/colors/darkolivegreen-chip.png" width=16 height=16 > rgb( 85, 107, 47).
	static Color darkolivegreen;

	/// \brief <img src="../../img/colors/darkorange-chip.png" width=16 height=16 > rgb(255, 140, 0).
	static Color darkorange;

	/// \brief <img src="../../img/colors/darkorchid-chip.png" width=16 height=16 > rgb(153, 50, 204).
	static Color darkorchid;

	/// \brief <img src="../../img/colors/darkred-chip.png" width=16 height=16 > rgb(139, 0, 0).
	static Color darkred;

	/// \brief <img src="../../img/colors/darksalmon-chip.png" width=16 height=16 > rgb(233, 150, 122).
	static Color darksalmon;

	/// \brief <img src="../../img/colors/darkseagreen-chip.png" width=16 height=16 > rgb(143, 188, 143).
	static Color darkseagreen;

	/// \brief <img src="../../img/colors/darkslateblue-chip.png" width=16 height=16 > rgb( 72, 61, 139).
	static Color darkslateblue;

	/// \brief <img src="../../img/colors/darkslategray-chip.png" width=16 height=16 > rgb( 47, 79, 79).
	static Color darkslategray;

	/// \brief <img src="../../img/colors/darkslategrey-chip.png" width=16 height=16 > rgb( 47, 79, 79).
	static Color darkslategrey;

	/// \brief <img src="../../img/colors/darkturquoise-chip.png" width=16 height=16 > rgb( 0, 206, 209).
	static Color darkturquoise;

	/// \brief <img src="../../img/colors/darkviolet-chip.png" width=16 height=16 > rgb(148, 0, 211).
	static Color darkviolet;

	/// \brief <img src="../../img/colors/deeppink-chip.png" width=16 height=16 > rgb(255, 20, 147).
	static Color deeppink;

	/// \brief <img src="../../img/colors/deepskyblue-chip.png" width=16 height=16 > rgb( 0, 191, 255).
	static Color deepskyblue;

	/// \brief <img src="../../img/colors/dimgray-chip.png" width=16 height=16 > rgb(105, 105, 105).
	static Color dimgray;

	/// \brief <img src="../../img/colors/dimgrey-chip.png" width=16 height=16 > rgb(105, 105, 105).
	static Color dimgrey;

	/// \brief <img src="../../img/colors/dodgerblue-chip.png" width=16 height=16 > rgb( 30, 144, 255).
	static Color dodgerblue;

	/// \brief <img src="../../img/colors/firebrick-chip.png" width=16 height=16 > rgb(178, 34, 34).
	static Color firebrick;

	/// \brief <img src="../../img/colors/floralwhite-chip.png" width=16 height=16 > rgb(255, 250, 240).
	static Color floralwhite;

	/// \brief <img src="../../img/colors/forestgreen-chip.png" width=16 height=16 > rgb( 34, 139, 34).
	static Color forestgreen;

	/// \brief <img src="../../img/colors/fuchsia-chip.png" width=16 height=16 > rgb(255, 0, 255).
	static Color fuchsia;

	/// \brief <img src="../../img/colors/gainsboro-chip.png" width=16 height=16 > rgb(220, 220, 220).
	static Color gainsboro;

	/// \brief <img src="../../img/colors/ghostwhite-chip.png" width=16 height=16 > rgb(248, 248, 255).
	static Color ghostwhite;

	/// \brief <img src="../../img/colors/gold-chip.png" width=16 height=16 > rgb(255, 215, 0).
	static Color gold;

	/// \brief <img src="../../img/colors/goldenrod-chip.png" width=16 height=16 > rgb(218, 165, 32).
	static Color goldenrod;

	/// \brief <img src="../../img/colors/gray-chip.png" width=16 height=16 > rgb(128, 128, 128).
	static Color gray;

	/// \brief <img src="../../img/colors/grey-chip.png" width=16 height=16 > rgb(128, 128, 128).
	static Color grey;

	/// \brief <img src="../../img/colors/green-chip.png" width=16 height=16 > rgb( 0, 128, 0).
	static Color green;

	/// \brief <img src="../../img/colors/greenyellow-chip.png" width=16 height=16 > rgb(173, 255, 47).
	static Color greenyellow;

	/// \brief <img src="../../img/colors/honeydew-chip.png" width=16 height=16 > rgb(240, 255, 240).
	static Color honeydew;

	/// \brief <img src="../../img/colors/hotpink-chip.png" width=16 height=16 > rgb(255, 105, 180).
	static Color hotpink;

	/// \brief <img src="../../img/colors/indianred-chip.png" width=16 height=16 > rgb(205, 92, 92).
	static Color indianred;

	/// \brief <img src="../../img/colors/indigo-chip.png" width=16 height=16 > rgb( 75, 0, 130).
	static Color indigo;

	/// \brief <img src="../../img/colors/ivory-chip.png" width=16 height=16 > rgb(255, 255, 240).
	static Color ivory;

	/// \brief <img src="../../img/colors/khaki-chip.png" width=16 height=16 > rgb(240, 230, 140).
	static Color khaki;

	/// \brief <img src="../../img/colors/lavender-chip.png" width=16 height=16 > rgb(230, 230, 250).
	static Color lavender;

	/// \brief <img src="../../img/colors/lavenderblush-chip.png" width=16 height=16 > rgb(255, 240, 245).
	static Color lavenderblush;

	/// \brief <img src="../../img/colors/lawngreen-chip.png" width=16 height=16 > rgb(124, 252, 0).
	static Color lawngreen;

	/// \brief <img src="../../img/colors/lemonchiffon-chip.png" width=16 height=16 > rgb(255, 250, 205).
	static Color lemonchiffon;

	/// \brief <img src="../../img/colors/lightblue-chip.png" width=16 height=16 > rgb(173, 216, 230).
	static Color lightblue;

	/// \brief <img src="../../img/colors/lightcoral-chip.png" width=16 height=16 > rgb(240, 128, 128).
	static Color lightcoral;

	/// \brief <img src="../../img/colors/lightcyan-chip.png" width=16 height=16 > rgb(224, 255, 255).
	static Color lightcyan;

	/// \brief <img src="../../img/colors/lightgoldenrodyellow-chip.png" width=16 height=16 > rgb(250, 250, 210).
	static Color lightgoldenrodyellow;

	/// \brief <img src="../../img/colors/lightgray-chip.png" width=16 height=16 > rgb(211, 211, 211).
	static Color lightgray;

	/// \brief <img src="../../img/colors/lightgreen-chip.png" width=16 height=16 > rgb(144, 238, 144).
	static Color lightgreen;

	/// \brief <img src="../../img/colors/lightgrey-chip.png" width=16 height=16 > rgb(211, 211, 211).
	static Color lightgrey;

	/// \brief <img src="../../img/colors/lightpink-chip.png" width=16 height=16 > rgb(255, 182, 193).
	static Color lightpink;

	/// \brief <img src="../../img/colors/lightsalmon-chip.png" width=16 height=16 > rgb(255, 160, 122).
	static Color lightsalmon;

	/// \brief <img src="../../img/colors/lightseagreen-chip.png" width=16 height=16 > rgb( 32, 178, 170).
	static Color lightseagreen;

	/// \brief <img src="../../img/colors/lightskyblue-chip.png" width=16 height=16 > rgb(135, 206, 250).
	static Color lightskyblue;

	/// \brief <img src="../../img/colors/lightslategray-chip.png" width=16 height=16 > rgb(119, 136, 153).
	static Color lightslategray;

	/// \brief <img src="../../img/colors/lightslategrey-chip.png" width=16 height=16 > rgb(119, 136, 153).
	static Color lightslategrey;

	/// \brief <img src="../../img/colors/lightsteelblue-chip.png" width=16 height=16 > rgb(176, 196, 222).
	static Color lightsteelblue;

	/// \brief <img src="../../img/colors/lightyellow-chip.png" width=16 height=16 > rgb(255, 255, 224).
	static Color lightyellow;

	/// \brief <img src="../../img/colors/lime-chip.png" width=16 height=16 > rgb( 0, 255, 0).
	static Color lime;

	/// \brief <img src="../../img/colors/limegreen-chip.png" width=16 height=16 > rgb( 50, 205, 50).
	static Color limegreen;

	/// \brief <img src="../../img/colors/linen-chip.png" width=16 height=16 > rgb(250, 240, 230).
	static Color linen;

	/// \brief <img src="../../img/colors/magenta-chip.png" width=16 height=16 > rgb(255, 0, 255).
	static Color magenta;

	/// \brief <img src="../../img/colors/maroon-chip.png" width=16 height=16 > rgb(128, 0, 0).
	static Color maroon;

	/// \brief <img src="../../img/colors/mediumaquamarine-chip.png" width=16 height=16 > rgb(102, 205, 170).
	static Color mediumaquamarine;

	/// \brief <img src="../../img/colors/mediumblue-chip.png" width=16 height=16 > rgb( 0, 0, 205).
	static Color mediumblue;

	/// \brief <img src="../../img/colors/mediumorchid-chip.png" width=16 height=16 > rgb(186, 85, 211).
	static Color mediumorchid;

	/// \brief <img src="../../img/colors/mediumpurple-chip.png" width=16 height=16 > rgb(147, 112, 219).
	static Color mediumpurple;

	/// \brief <img src="../../img/colors/mediumseagreen-chip.png" width=16 height=16 > rgb( 60, 179, 113).
	static Color mediumseagreen;

	/// \brief <img src="../../img/colors/mediumslateblue-chip.png" width=16 height=16 > rgb(123, 104, 238).
	static Color mediumslateblue;

	/// \brief <img src="../../img/colors/mediumspringgreen-chip.png" width=16 height=16 > rgb( 0, 250, 154).
	static Color mediumspringgreen;

	/// \brief <img src="../../img/colors/mediumturquoise-chip.png" width=16 height=16 > rgb( 72, 209, 204).
	static Color mediumturquoise;

	/// \brief <img src="../../img/colors/mediumvioletred-chip.png" width=16 height=16 > rgb(199, 21, 133).
	static Color mediumvioletred;

	/// \brief <img src="../../img/colors/midnightblue-chip.png" width=16 height=16 > rgb( 25, 25, 112).
	static Color midnightblue;

	/// \brief <img src="../../img/colors/mintcream-chip.png" width=16 height=16 > rgb(245, 255, 250).
	static Color mintcream;

	/// \brief <img src="../../img/colors/mistyrose-chip.png" width=16 height=16 > rgb(255, 228, 225).
	static Color mistyrose;

	/// \brief <img src="../../img/colors/moccasin-chip.png" width=16 height=16 > rgb(255, 228, 181).
	static Color moccasin;

	/// \brief <img src="../../img/colors/navajowhite-chip.png" width=16 height=16 > rgb(255, 222, 173).
	static Color navajowhite;

	/// \brief <img src="../../img/colors/navy-chip.png" width=16 height=16 > rgb( 0, 0, 128).
	static Color navy;

	/// \brief <img src="../../img/colors/oldlace-chip.png" width=16 height=16 > rgb(253, 245, 230).
	static Color oldlace;

	/// \brief <img src="../../img/colors/olive-chip.png" width=16 height=16 > rgb(128, 128, 0).
	static Color olive;

	/// \brief <img src="../../img/colors/olivedrab-chip.png" width=16 height=16 > rgb(107, 142, 35).
	static Color olivedrab;

	/// \brief <img src="../../img/colors/orange-chip.png" width=16 height=16 > rgb(255, 165, 0).
	static Color orange;

	/// \brief <img src="../../img/colors/orangered-chip.png" width=16 height=16 > rgb(255, 69, 0).
	static Color orangered;

	/// \brief <img src="../../img/colors/orchid-chip.png" width=16 height=16 > rgb(218, 112, 214).
	static Color orchid;

	/// \brief <img src="../../img/colors/palegoldenrod-chip.png" width=16 height=16 > rgb(238, 232, 170).
	static Color palegoldenrod;

	/// \brief <img src="../../img/colors/palegreen-chip.png" width=16 height=16 > rgb(152, 251, 152).
	static Color palegreen;

	/// \brief <img src="../../img/colors/paleturquoise-chip.png" width=16 height=16 > rgb(175, 238, 238).
	static Color paleturquoise;

	/// \brief <img src="../../img/colors/palevioletred-chip.png" width=16 height=16 > rgb(219, 112, 147).
	static Color palevioletred;

	/// \brief <img src="../../img/colors/papayawhip-chip.png" width=16 height=16 > rgb(255, 239, 213).
	static Color papayawhip;

	/// \brief <img src="../../img/colors/peachpuff-chip.png" width=16 height=16 > rgb(255, 218, 185).
	static Color peachpuff;

	/// \brief <img src="../../img/colors/peru-chip.png" width=16 height=16 > rgb(205, 133, 63).
	static Color peru;

	/// \brief <img src="../../img/colors/pink-chip.png" width=16 height=16 > rgb(255, 192, 203).
	static Color pink;

	/// \brief <img src="../../img/colors/plum-chip.png" width=16 height=16 > rgb(221, 160, 221).
	static Color plum;

	/// \brief <img src="../../img/colors/powderblue-chip.png" width=16 height=16 > rgb(176, 224, 230).
	static Color powderblue;

	/// \brief <img src="../../img/colors/purple-chip.png" width=16 height=16 > rgb(128, 0, 128).
	static Color purple;

	/// \brief <img src="../../img/colors/red-chip.png" width=16 height=16 > rgb(255, 0, 0).
	static Color red;

	/// \brief <img src="../../img/colors/rosybrown-chip.png" width=16 height=16 > rgb(188, 143, 143).
	static Color rosybrown;

	/// \brief <img src="../../img/colors/royalblue-chip.png" width=16 height=16 > rgb( 65, 105, 225).
	static Color royalblue;

	/// \brief <img src="../../img/colors/saddlebrown-chip.png" width=16 height=16 > rgb(139, 69, 19).
	static Color saddlebrown;

	/// \brief <img src="../../img/colors/salmon-chip.png" width=16 height=16 > rgb(250, 128, 114).
	static Color salmon;

	/// \brief <img src="../../img/colors/sandybrown-chip.png" width=16 height=16 > rgb(244, 164, 96).
	static Color sandybrown;

	/// \brief <img src="../../img/colors/seagreen-chip.png" width=16 height=16 > rgb( 46, 139, 87).
	static Color seagreen;

	/// \brief <img src="../../img/colors/seashell-chip.png" width=16 height=16 > rgb(255, 245, 238).
	static Color seashell;

	/// \brief <img src="../../img/colors/sienna-chip.png" width=16 height=16 > rgb(160, 82, 45).
	static Color sienna;

	/// \brief <img src="../../img/colors/silver-chip.png" width=16 height=16 > rgb(192, 192, 192).
	static Color silver;

	/// \brief <img src="../../img/colors/skyblue-chip.png" width=16 height=16 > rgb(135, 206, 235).
	static Color skyblue;

	/// \brief <img src="../../img/colors/slateblue-chip.png" width=16 height=16 > rgb(106, 90, 205).
	static Color slateblue;

	/// \brief <img src="../../img/colors/slategray-chip.png" width=16 height=16 > rgb(112, 128, 144).
	static Color slategray;

	/// \brief <img src="../../img/colors/slategrey-chip.png" width=16 height=16 > rgb(112, 128, 144).
	static Color slategrey;

	/// \brief <img src="../../img/colors/snow-chip.png" width=16 height=16 > rgb(255, 250, 250).
	static Color snow;

	/// \brief <img src="../../img/colors/springgreen-chip.png" width=16 height=16 > rgb( 0, 255, 127).
	static Color springgreen;

	/// \brief <img src="../../img/colors/steelblue-chip.png" width=16 height=16 > rgb( 70, 130, 180).
	static Color steelblue;

	/// \brief <img src="../../img/colors/tan-chip.png" width=16 height=16 > rgb(210, 180, 140).
	static Color tan;

	/// \brief <img src="../../img/colors/teal-chip.png" width=16 height=16 > rgb( 0, 128, 128).
	static Color teal;

	/// \brief <img src="../../img/colors/thistle-chip.png" width=16 height=16 > rgb(216, 191, 216).
	static Color thistle;

	/// \brief <img src="../../img/colors/tomato-chip.png" width=16 height=16 > rgb(255, 99, 71).
	static Color tomato;

	/// \brief <img src="../../img/colors/turquoise-chip.png" width=16 height=16 > rgb( 64, 224, 208).
	static Color turquoise;

	/// \brief <img src="../../img/colors/violet-chip.png" width=16 height=16 > rgb(238, 130, 238).
	static Color violet;

	/// \brief <img src="../../img/colors/wheat-chip.png" width=16 height=16 > rgb(245, 222, 179).
	static Color wheat;

	/// \brief <img src="../../img/colors/white-chip.png" width=16 height=16 > rgb(255, 255, 255).
	static Color white;

	/// \brief <img src="../../img/colors/whitesmoke-chip.png" width=16 height=16 > rgb(245, 245, 245).
	static Color whitesmoke;

	/// \brief <img src="../../img/colors/yellow-chip.png" width=16 height=16 > rgb(255, 255, 0).
	static Color yellow;

	/// \brief <img src="../../img/colors/yellowgreen-chip.png" width=16 height=16 > rgb(154, 205, 50).
	static Color yellowgreen;

	/// \brief rgba(0, 0, 0, 0).
	static Color transparent;

	static Color gray10;
	static Color gray20;
	static Color gray30;
	static Color gray40;
	static Color gray50;
	static Color gray60;
	static Color gray70;
	static Color gray80;
	static Color gray90;

	// Find and returns the static color matching a string.
	// Name of color to match, eg. "blue".
	static Color find_color(const std::string &name);

	// Returns the names of static colors defined.
	static std::vector<std::string> &get_names();

	// Range 0 - 255
	void set_alpha(unsigned char value) { a = value; }
	void set_red(unsigned char value) {  r = value; }
	void set_green(unsigned char value) { g = value; }
	void set_blue(unsigned char value) { b = value; }

	// Range 0.0 - 1.0
	void set_alpha_f(float value) { a = (unsigned char) (value*255.0f); }
	void set_red_f(float value) { r = (unsigned char) (value*255.0f); }
	void set_green_f(float value) { g = (unsigned char) (value*255.0f); }
	void set_blue_f(float value) { b = (unsigned char) (value*255.0f); }

	// Range 0 - 255
	void set_color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255)
	{ r = red; g =  green; b = blue;  a = alpha; }

	void set_rgba8(unsigned int color);
	void set_bgra8(unsigned int color);
	void set_rgb8(unsigned int color);
	void set_argb8(unsigned int color);

	// Range 0.0 - 1.0
	void set_colorf(float red, float green, float blue, float alpha = 1.0f)
	{
		r = (unsigned char) (red * 255.0f);
		g = (unsigned char) (green * 255.0f);
		b = (unsigned char) (blue * 255.0f);
		a = (unsigned char) (alpha * 255.0f);
	}

protected:
	static unsigned char hex[]; /* = { '0', '1', '2', '3', '4', '5', '6', '7',
		'8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };*/
};

class Colorf : public glm::vec4
{
public:
	Colorf() : glm::vec4(0.0f, 0.0f, 0.0f, 0.0f)
	{
	}

	Colorf(float r, float g, float b, float a = 1.0f) : glm::vec4(r, g, b, a)
	{
	}

	Colorf(const float *array_rgba)
		: glm::vec4((array_rgba[0]), (array_rgba[1]), (array_rgba[2]), (array_rgba[3]))
	{
	}

	Colorf(unsigned char r, unsigned char g, unsigned char b, unsigned char a=255)
		: glm::vec4((r / 255.0f), (g / 255.0f), (b / 255.0f), (a / 255.0f))
	{
	}

	Colorf(int r, int g, int b, int a=255)
		: glm::vec4((r / 255.0f), (g / 255.0f), (b / 255.0f), (a / 255.0f))
	{
	}

	explicit Colorf(const Color& color)
		: glm::vec4((color.get_red() / 255.0f), (color.get_green() / 255.0f), (color.get_blue() / 255.0f), (color.get_alpha() / 255.0f))
	{
	}

	Colorf(const std::string &hexstr)
	{
		*this = (Colorf)Color::find_color(hexstr);
	}

	float get_red() const { return r; }
	float get_green() const { return g; }
	float get_blue() const { return b; }
	float get_alpha() const { return a; }

	// Normalize the color by ensuring that all color values lie inbetween (0.0, 1.0)
	void normalize()
	{
		r = (r < 0.0f) ? 0.0f : ((r > 1.0f) ? 1.0f : r);
		g = (g < 0.0f) ? 0.0f : ((g > 1.0f) ? 1.0f : g);
		b = (b < 0.0f) ? 0.0f : ((b > 1.0f) ? 1.0f : b);
		a = (a < 0.0f) ? 0.0f : ((a > 1.0f) ? 1.0f : a);
	}

	void set_alpha(float value) { a = value; }
	void set_red(float value) {  r = value; }
	void set_green(float value) { g= value; }
	void set_blue(float value) { b = value; }

	bool operator==(const Colorf &c) const
	{
		return (r == c.r) && (g == c.g) && (b == c.b) && (a == c.a);
	}

	bool operator!=(const Colorf &c) const
	{
		return (r != c.r) || (g != c.g) || (b != c.b) || (a != c.a);
	}

	operator Color() const
	{
		return Color(*this);
	}

	/// \brief <img src="../../img/colors/aliceblue-chip.png" width=16 height=16 > rgb(240, 248, 255).
	static Colorf aliceblue;

	/// \brief <img src="../../img/colors/antiquewhite-chip.png" width=16 height=16 > rgb(250, 235, 215).
	static Colorf antiquewhite;

	/// \brief <img src="../../img/colors/aqua-chip.png" width=16 height=16 > rgb( 0, 255, 255).
	static Colorf aqua;

	/// \brief <img src="../../img/colors/aquamarine-chip.png" width=16 height=16 > rgb(127, 255, 212).
	static Colorf aquamarine;

	/// \brief <img src="../../img/colors/azure-chip.png" width=16 height=16 > rgb(240, 255, 255).
	static Colorf azure;

	/// \brief <img src="../../img/colors/beige-chip.png" width=16 height=16 > rgb(245, 245, 220).
	static Colorf beige;

	/// \brief <img src="../../img/colors/bisque-chip.png" width=16 height=16 > rgb(255, 228, 196).
	static Colorf bisque;

	/// \brief <img src="../../img/colors/black-chip.png" width=16 height=16 > rgb( 0, 0, 0).
	static Colorf black;

	/// \brief <img src="../../img/colors/blanchedalmond-chip.png" width=16 height=16 > rgb(255, 235, 205).
	static Colorf blanchedalmond;

	/// \brief <img src="../../img/colors/blue-chip.png" width=16 height=16 > rgb( 0, 0, 255).
	static Colorf blue;

	/// \brief <img src="../../img/colors/blueviolet-chip.png" width=16 height=16 > rgb(138, 43, 226).
	static Colorf blueviolet;

	/// \brief <img src="../../img/colors/brown-chip.png" width=16 height=16 > rgb(165, 42, 42).
	static Colorf brown;

	/// \brief <img src="../../img/colors/burlywood-chip.png" width=16 height=16 > rgb(222, 184, 135).
	static Colorf burlywood;

	/// \brief <img src="../../img/colors/cadetblue-chip.png" width=16 height=16 > rgb( 95, 158, 160).
	static Colorf cadetblue;

	/// \brief <img src="../../img/colors/chartreuse-chip.png" width=16 height=16 > rgb(127, 255, 0).
	static Colorf chartreuse;

	/// \brief <img src="../../img/colors/chocolate-chip.png" width=16 height=16 > rgb(210, 105, 30).
	static Colorf chocolate;

	/// \brief <img src="../../img/colors/coral-chip.png" width=16 height=16 > rgb(255, 127, 80).
	static Colorf coral;

	/// \brief <img src="../../img/colors/cornflowerblue-chip.png" width=16 height=16 > rgb(100, 149, 237).
	static Colorf cornflowerblue;

	/// \brief <img src="../../img/colors/cornsilk-chip.png" width=16 height=16 > rgb(255, 248, 220).
	static Colorf cornsilk;

	/// \brief <img src="../../img/colors/crimson-chip.png" width=16 height=16 > rgb(220, 20, 60).
	static Colorf crimson;

	/// \brief <img src="../../img/colors/cyan-chip.png" width=16 height=16 > rgb( 0, 255, 255).
	static Colorf cyan;

	/// \brief <img src="../../img/colors/darkblue-chip.png" width=16 height=16 > rgb( 0, 0, 139).
	static Colorf darkblue;

	/// \brief <img src="../../img/colors/darkcyan-chip.png" width=16 height=16 > rgb( 0, 139, 139).
	static Colorf darkcyan;

	/// \brief <img src="../../img/colors/darkgoldenrod-chip.png" width=16 height=16 > rgb(184, 134, 11).
	static Colorf darkgoldenrod;

	/// \brief <img src="../../img/colors/darkgray-chip.png" width=16 height=16 > rgb(169, 169, 169).
	static Colorf darkgray;

	/// \brief <img src="../../img/colors/darkgreen-chip.png" width=16 height=16 > rgb( 0, 100, 0).
	static Colorf darkgreen;

	/// \brief <img src="../../img/colors/darkgrey-chip.png" width=16 height=16 > rgb(169, 169, 169).
	static Colorf darkgrey;

	/// \brief <img src="../../img/colors/darkkhaki-chip.png" width=16 height=16 > rgb(189, 183, 107).
	static Colorf darkkhaki;

	/// \brief <img src="../../img/colors/darkmagenta-chip.png" width=16 height=16 > rgb(139, 0, 139).
	static Colorf darkmagenta;

	/// \brief <img src="../../img/colors/darkolivegreen-chip.png" width=16 height=16 > rgb( 85, 107, 47).
	static Colorf darkolivegreen;

	/// \brief <img src="../../img/colors/darkorange-chip.png" width=16 height=16 > rgb(255, 140, 0).
	static Colorf darkorange;

	/// \brief <img src="../../img/colors/darkorchid-chip.png" width=16 height=16 > rgb(153, 50, 204).
	static Colorf darkorchid;

	/// \brief <img src="../../img/colors/darkred-chip.png" width=16 height=16 > rgb(139, 0, 0).
	static Colorf darkred;

	/// \brief <img src="../../img/colors/darksalmon-chip.png" width=16 height=16 > rgb(233, 150, 122).
	static Colorf darksalmon;

	/// \brief <img src="../../img/colors/darkseagreen-chip.png" width=16 height=16 > rgb(143, 188, 143).
	static Colorf darkseagreen;

	/// \brief <img src="../../img/colors/darkslateblue-chip.png" width=16 height=16 > rgb( 72, 61, 139).
	static Colorf darkslateblue;

	/// \brief <img src="../../img/colors/darkslategray-chip.png" width=16 height=16 > rgb( 47, 79, 79).
	static Colorf darkslategray;

	/// \brief <img src="../../img/colors/darkslategrey-chip.png" width=16 height=16 > rgb( 47, 79, 79).
	static Colorf darkslategrey;

	/// \brief <img src="../../img/colors/darkturquoise-chip.png" width=16 height=16 > rgb( 0, 206, 209).
	static Colorf darkturquoise;

	/// \brief <img src="../../img/colors/darkviolet-chip.png" width=16 height=16 > rgb(148, 0, 211).
	static Colorf darkviolet;

	/// \brief <img src="../../img/colors/deeppink-chip.png" width=16 height=16 > rgb(255, 20, 147).
	static Colorf deeppink;

	/// \brief <img src="../../img/colors/deepskyblue-chip.png" width=16 height=16 > rgb( 0, 191, 255).
	static Colorf deepskyblue;

	/// \brief <img src="../../img/colors/dimgray-chip.png" width=16 height=16 > rgb(105, 105, 105).
	static Colorf dimgray;

	/// \brief <img src="../../img/colors/dimgrey-chip.png" width=16 height=16 > rgb(105, 105, 105).
	static Colorf dimgrey;

	/// \brief <img src="../../img/colors/dodgerblue-chip.png" width=16 height=16 > rgb( 30, 144, 255).
	static Colorf dodgerblue;

	/// \brief <img src="../../img/colors/firebrick-chip.png" width=16 height=16 > rgb(178, 34, 34).
	static Colorf firebrick;

	/// \brief <img src="../../img/colors/floralwhite-chip.png" width=16 height=16 > rgb(255, 250, 240).
	static Colorf floralwhite;

	/// \brief <img src="../../img/colors/forestgreen-chip.png" width=16 height=16 > rgb( 34, 139, 34).
	static Colorf forestgreen;

	/// \brief <img src="../../img/colors/fuchsia-chip.png" width=16 height=16 > rgb(255, 0, 255).
	static Colorf fuchsia;

	/// \brief <img src="../../img/colors/gainsboro-chip.png" width=16 height=16 > rgb(220, 220, 220).
	static Colorf gainsboro;

	/// \brief <img src="../../img/colors/ghostwhite-chip.png" width=16 height=16 > rgb(248, 248, 255).
	static Colorf ghostwhite;

	/// \brief <img src="../../img/colors/gold-chip.png" width=16 height=16 > rgb(255, 215, 0).
	static Colorf gold;

	/// \brief <img src="../../img/colors/goldenrod-chip.png" width=16 height=16 > rgb(218, 165, 32).
	static Colorf goldenrod;

	/// \brief <img src="../../img/colors/gray-chip.png" width=16 height=16 > rgb(128, 128, 128).
	static Colorf gray;

	/// \brief <img src="../../img/colors/grey-chip.png" width=16 height=16 > rgb(128, 128, 128).
	static Colorf grey;

	/// \brief <img src="../../img/colors/green-chip.png" width=16 height=16 > rgb( 0, 128, 0).
	static Colorf green;

	/// \brief <img src="../../img/colors/greenyellow-chip.png" width=16 height=16 > rgb(173, 255, 47).
	static Colorf greenyellow;

	/// \brief <img src="../../img/colors/honeydew-chip.png" width=16 height=16 > rgb(240, 255, 240).
	static Colorf honeydew;

	/// \brief <img src="../../img/colors/hotpink-chip.png" width=16 height=16 > rgb(255, 105, 180).
	static Colorf hotpink;

	/// \brief <img src="../../img/colors/indianred-chip.png" width=16 height=16 > rgb(205, 92, 92).
	static Colorf indianred;

	/// \brief <img src="../../img/colors/indigo-chip.png" width=16 height=16 > rgb( 75, 0, 130).
	static Colorf indigo;

	/// \brief <img src="../../img/colors/ivory-chip.png" width=16 height=16 > rgb(255, 255, 240).
	static Colorf ivory;

	/// \brief <img src="../../img/colors/khaki-chip.png" width=16 height=16 > rgb(240, 230, 140).
	static Colorf khaki;

	/// \brief <img src="../../img/colors/lavender-chip.png" width=16 height=16 > rgb(230, 230, 250).
	static Colorf lavender;

	/// \brief <img src="../../img/colors/lavenderblush-chip.png" width=16 height=16 > rgb(255, 240, 245).
	static Colorf lavenderblush;

	/// \brief <img src="../../img/colors/lawngreen-chip.png" width=16 height=16 > rgb(124, 252, 0).
	static Colorf lawngreen;

	/// \brief <img src="../../img/colors/lemonchiffon-chip.png" width=16 height=16 > rgb(255, 250, 205).
	static Colorf lemonchiffon;

	/// \brief <img src="../../img/colors/lightblue-chip.png" width=16 height=16 > rgb(173, 216, 230).
	static Colorf lightblue;

	/// \brief <img src="../../img/colors/lightcoral-chip.png" width=16 height=16 > rgb(240, 128, 128).
	static Colorf lightcoral;

	/// \brief <img src="../../img/colors/lightcyan-chip.png" width=16 height=16 > rgb(224, 255, 255).
	static Colorf lightcyan;

	/// \brief <img src="../../img/colors/lightgoldenrodyellow-chip.png" width=16 height=16 > rgb(250, 250, 210).
	static Colorf lightgoldenrodyellow;

	/// \brief <img src="../../img/colors/lightgray-chip.png" width=16 height=16 > rgb(211, 211, 211).
	static Colorf lightgray;

	/// \brief <img src="../../img/colors/lightgreen-chip.png" width=16 height=16 > rgb(144, 238, 144).
	static Colorf lightgreen;

	/// \brief <img src="../../img/colors/lightgrey-chip.png" width=16 height=16 > rgb(211, 211, 211).
	static Colorf lightgrey;

	/// \brief <img src="../../img/colors/lightpink-chip.png" width=16 height=16 > rgb(255, 182, 193).
	static Colorf lightpink;

	/// \brief <img src="../../img/colors/lightsalmon-chip.png" width=16 height=16 > rgb(255, 160, 122).
	static Colorf lightsalmon;

	/// \brief <img src="../../img/colors/lightseagreen-chip.png" width=16 height=16 > rgb( 32, 178, 170).
	static Colorf lightseagreen;

	/// \brief <img src="../../img/colors/lightskyblue-chip.png" width=16 height=16 > rgb(135, 206, 250).
	static Colorf lightskyblue;

	/// \brief <img src="../../img/colors/lightslategray-chip.png" width=16 height=16 > rgb(119, 136, 153).
	static Colorf lightslategray;

	/// \brief <img src="../../img/colors/lightslategrey-chip.png" width=16 height=16 > rgb(119, 136, 153).
	static Colorf lightslategrey;

	/// \brief <img src="../../img/colors/lightsteelblue-chip.png" width=16 height=16 > rgb(176, 196, 222).
	static Colorf lightsteelblue;

	/// \brief <img src="../../img/colors/lightyellow-chip.png" width=16 height=16 > rgb(255, 255, 224).
	static Colorf lightyellow;

	/// \brief <img src="../../img/colors/lime-chip.png" width=16 height=16 > rgb( 0, 255, 0).
	static Colorf lime;

	/// \brief <img src="../../img/colors/limegreen-chip.png" width=16 height=16 > rgb( 50, 205, 50).
	static Colorf limegreen;

	/// \brief <img src="../../img/colors/linen-chip.png" width=16 height=16 > rgb(250, 240, 230).
	static Colorf linen;

	/// \brief <img src="../../img/colors/magenta-chip.png" width=16 height=16 > rgb(255, 0, 255).
	static Colorf magenta;

	/// \brief <img src="../../img/colors/maroon-chip.png" width=16 height=16 > rgb(128, 0, 0).
	static Colorf maroon;

	/// \brief <img src="../../img/colors/mediumaquamarine-chip.png" width=16 height=16 > rgb(102, 205, 170).
	static Colorf mediumaquamarine;

	/// \brief <img src="../../img/colors/mediumblue-chip.png" width=16 height=16 > rgb( 0, 0, 205).
	static Colorf mediumblue;

	/// \brief <img src="../../img/colors/mediumorchid-chip.png" width=16 height=16 > rgb(186, 85, 211).
	static Colorf mediumorchid;

	/// \brief <img src="../../img/colors/mediumpurple-chip.png" width=16 height=16 > rgb(147, 112, 219).
	static Colorf mediumpurple;

	/// \brief <img src="../../img/colors/mediumseagreen-chip.png" width=16 height=16 > rgb( 60, 179, 113).
	static Colorf mediumseagreen;

	/// \brief <img src="../../img/colors/mediumslateblue-chip.png" width=16 height=16 > rgb(123, 104, 238).
	static Colorf mediumslateblue;

	/// \brief <img src="../../img/colors/mediumspringgreen-chip.png" width=16 height=16 > rgb( 0, 250, 154).
	static Colorf mediumspringgreen;

	/// \brief <img src="../../img/colors/mediumturquoise-chip.png" width=16 height=16 > rgb( 72, 209, 204).
	static Colorf mediumturquoise;

	/// \brief <img src="../../img/colors/mediumvioletred-chip.png" width=16 height=16 > rgb(199, 21, 133).
	static Colorf mediumvioletred;

	/// \brief <img src="../../img/colors/midnightblue-chip.png" width=16 height=16 > rgb( 25, 25, 112).
	static Colorf midnightblue;

	/// \brief <img src="../../img/colors/mintcream-chip.png" width=16 height=16 > rgb(245, 255, 250).
	static Colorf mintcream;

	/// \brief <img src="../../img/colors/mistyrose-chip.png" width=16 height=16 > rgb(255, 228, 225).
	static Colorf mistyrose;

	/// \brief <img src="../../img/colors/moccasin-chip.png" width=16 height=16 > rgb(255, 228, 181).
	static Colorf moccasin;

	/// \brief <img src="../../img/colors/navajowhite-chip.png" width=16 height=16 > rgb(255, 222, 173).
	static Colorf navajowhite;

	/// \brief <img src="../../img/colors/navy-chip.png" width=16 height=16 > rgb( 0, 0, 128).
	static Colorf navy;

	/// \brief <img src="../../img/colors/oldlace-chip.png" width=16 height=16 > rgb(253, 245, 230).
	static Colorf oldlace;

	/// \brief <img src="../../img/colors/olive-chip.png" width=16 height=16 > rgb(128, 128, 0).
	static Colorf olive;

	/// \brief <img src="../../img/colors/olivedrab-chip.png" width=16 height=16 > rgb(107, 142, 35).
	static Colorf olivedrab;

	/// \brief <img src="../../img/colors/orange-chip.png" width=16 height=16 > rgb(255, 165, 0).
	static Colorf orange;

	/// \brief <img src="../../img/colors/orangered-chip.png" width=16 height=16 > rgb(255, 69, 0).
	static Colorf orangered;

	/// \brief <img src="../../img/colors/orchid-chip.png" width=16 height=16 > rgb(218, 112, 214).
	static Colorf orchid;

	/// \brief <img src="../../img/colors/palegoldenrod-chip.png" width=16 height=16 > rgb(238, 232, 170).
	static Colorf palegoldenrod;

	/// \brief <img src="../../img/colors/palegreen-chip.png" width=16 height=16 > rgb(152, 251, 152).
	static Colorf palegreen;

	/// \brief <img src="../../img/colors/paleturquoise-chip.png" width=16 height=16 > rgb(175, 238, 238).
	static Colorf paleturquoise;

	/// \brief <img src="../../img/colors/palevioletred-chip.png" width=16 height=16 > rgb(219, 112, 147).
	static Colorf palevioletred;

	/// \brief <img src="../../img/colors/papayawhip-chip.png" width=16 height=16 > rgb(255, 239, 213).
	static Colorf papayawhip;

	/// \brief <img src="../../img/colors/peachpuff-chip.png" width=16 height=16 > rgb(255, 218, 185).
	static Colorf peachpuff;

	/// \brief <img src="../../img/colors/peru-chip.png" width=16 height=16 > rgb(205, 133, 63).
	static Colorf peru;

	/// \brief <img src="../../img/colors/pink-chip.png" width=16 height=16 > rgb(255, 192, 203).
	static Colorf pink;

	/// \brief <img src="../../img/colors/plum-chip.png" width=16 height=16 > rgb(221, 160, 221).
	static Colorf plum;

	/// \brief <img src="../../img/colors/powderblue-chip.png" width=16 height=16 > rgb(176, 224, 230).
	static Colorf powderblue;

	/// \brief <img src="../../img/colors/purple-chip.png" width=16 height=16 > rgb(128, 0, 128).
	static Colorf purple;

	/// \brief <img src="../../img/colors/red-chip.png" width=16 height=16 > rgb(255, 0, 0).
	static Colorf red;

	/// \brief <img src="../../img/colors/rosybrown-chip.png" width=16 height=16 > rgb(188, 143, 143).
	static Colorf rosybrown;

	/// \brief <img src="../../img/colors/royalblue-chip.png" width=16 height=16 > rgb( 65, 105, 225).
	static Colorf royalblue;

	/// \brief <img src="../../img/colors/saddlebrown-chip.png" width=16 height=16 > rgb(139, 69, 19).
	static Colorf saddlebrown;

	/// \brief <img src="../../img/colors/salmon-chip.png" width=16 height=16 > rgb(250, 128, 114).
	static Colorf salmon;

	/// \brief <img src="../../img/colors/sandybrown-chip.png" width=16 height=16 > rgb(244, 164, 96).
	static Colorf sandybrown;

	/// \brief <img src="../../img/colors/seagreen-chip.png" width=16 height=16 > rgb( 46, 139, 87).
	static Colorf seagreen;

	/// \brief <img src="../../img/colors/seashell-chip.png" width=16 height=16 > rgb(255, 245, 238).
	static Colorf seashell;

	/// \brief <img src="../../img/colors/sienna-chip.png" width=16 height=16 > rgb(160, 82, 45).
	static Colorf sienna;

	/// \brief <img src="../../img/colors/silver-chip.png" width=16 height=16 > rgb(192, 192, 192).
	static Colorf silver;

	/// \brief <img src="../../img/colors/skyblue-chip.png" width=16 height=16 > rgb(135, 206, 235).
	static Colorf skyblue;

	/// \brief <img src="../../img/colors/slateblue-chip.png" width=16 height=16 > rgb(106, 90, 205).
	static Colorf slateblue;

	/// \brief <img src="../../img/colors/slategray-chip.png" width=16 height=16 > rgb(112, 128, 144).
	static Colorf slategray;

	/// \brief <img src="../../img/colors/slategrey-chip.png" width=16 height=16 > rgb(112, 128, 144).
	static Colorf slategrey;

	/// \brief <img src="../../img/colors/snow-chip.png" width=16 height=16 > rgb(255, 250, 250).
	static Colorf snow;

	/// \brief <img src="../../img/colors/springgreen-chip.png" width=16 height=16 > rgb( 0, 255, 127).
	static Colorf springgreen;

	/// \brief <img src="../../img/colors/steelblue-chip.png" width=16 height=16 > rgb( 70, 130, 180).
	static Colorf steelblue;

	/// \brief <img src="../../img/colors/tan-chip.png" width=16 height=16 > rgb(210, 180, 140).
	static Colorf tan;

	/// \brief <img src="../../img/colors/teal-chip.png" width=16 height=16 > rgb( 0, 128, 128).
	static Colorf teal;

	/// \brief <img src="../../img/colors/thistle-chip.png" width=16 height=16 > rgb(216, 191, 216).
	static Colorf thistle;

	/// \brief <img src="../../img/colors/tomato-chip.png" width=16 height=16 > rgb(255, 99, 71).
	static Colorf tomato;

	/// \brief <img src="../../img/colors/turquoise-chip.png" width=16 height=16 > rgb( 64, 224, 208).
	static Colorf turquoise;

	/// \brief <img src="../../img/colors/violet-chip.png" width=16 height=16 > rgb(238, 130, 238).
	static Colorf violet;

	/// \brief <img src="../../img/colors/wheat-chip.png" width=16 height=16 > rgb(245, 222, 179).
	static Colorf wheat;

	/// \brief <img src="../../img/colors/white-chip.png" width=16 height=16 > rgb(255, 255, 255).
	static Colorf white;

	/// \brief <img src="../../img/colors/whitesmoke-chip.png" width=16 height=16 > rgb(245, 245, 245).
	static Colorf whitesmoke;

	/// \brief <img src="../../img/colors/yellow-chip.png" width=16 height=16 > rgb(255, 255, 0).
	static Colorf yellow;

	/// \brief <img src="../../img/colors/yellowgreen-chip.png" width=16 height=16 > rgb(154, 205, 50).
	static Colorf yellowgreen;

	/// \brief rgba(0, 0, 0, 0).
	static Colorf transparent;

	static Colorf gray10;
	static Colorf gray20;
	static Colorf gray30;
	static Colorf gray40;
	static Colorf gray50;
	static Colorf gray60;
	static Colorf gray70;
	static Colorf gray80;
	static Colorf gray90;
};

}
}

