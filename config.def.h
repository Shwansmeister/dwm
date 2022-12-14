/* See LICENSE file for copyright and license details. */

/* constants */
#define myTerm "alacritty"
#define myBrowser "qutebrowser"
/* appearance */
static const unsigned int borderpx       = 2;   /* border pixel of windows */
static const unsigned int snap           = 32;  /* snap pixel */
static const int swallowfloating         = 0;   /* 1 means swallow floating windows by default */
static const unsigned int gappih         = 10;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;  /* vert inner gap between windows */
static const unsigned int gappoh         = 10;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 10;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 1;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const char autostartblocksh[]     = "autostart_blocking.sh";
static const char autostartsh[]          = "autostart.sh";
static const char dwmdir[]               = "dwm";
static const char localshare[]           = ".local/share";
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
static const int bar_height              = 58;   /* 0 means derive from font, >= 1 explicit height */
/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int statusmon               = -1;
static const int horizpadbar             = 2;   /* horizontal padding for statusbar */
static const int vertpadbar              = 0;   /* vertical padding for statusbar */
static const unsigned int ulinepad       = 5;         /* horizontal padding between the underline and tag */
static const unsigned int ulinestroke  = 0;     /* thickness / height of the underline */
static const unsigned int ulinevoffset = 1;     /* how far above the bottom of the bar the line should appear */
static const int ulineall = 0;                  /* 1 to show underline on all tags, 0 for just the active ones */


/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_BOTTOM_BAR;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
static const int quit_empty_window_count = 1;   /* only allow dwm to quit if no (<= count) windows are open */
static const char *fonts[]               = { "mononokiNerdFontMono:size=8" }; //{ "SauceCodeProNerdFontMono:size=8" };
static const char dmenufont[]            = "mononokiNerdFontMono:size=8" ;

static char c000000[]                    = "#000000"; // placeholder value

static char normfgcolor[]                = "#d3c6aa";
static char normbgcolor[]                = "#2f383e";
static char normbordercolor[]            = "#2f383e";
static char normfloatcolor[]             = "#83c092";

static char selfgcolor[]                 = "#d3c6aa";
static char selbgcolor[]                 = "#2f383e";
static char selbordercolor[]             = "#a6c080";
static char selfloatcolor[]              = "#a6c080";

static char titlenormfgcolor[]           = "#e67e80";
static char titlenormbgcolor[]           = "#a6c080";
static char titlenormbordercolor[]       = "#e67e80";
static char titlenormfloatcolor[]        = "#e67e80";

static char titleselfgcolor[]            = "#2f383e";
static char titleselbgcolor[]            = "#a6c080";
static char titleselbordercolor[]        = "#e67e80";
static char titleselfloatcolor[]         = "#e67e80";

static char tagsnormfgcolor[]            = "#d3c6aa";
static char tagsnormbgcolor[]            = "#2f383e";
static char tagsnormbordercolor[]        = "#e67e80";
static char tagsnormfloatcolor[]         = "#e67e80";

static char tagsselfgcolor[]             = "#2f383e";
static char tagsselbgcolor[]             = "#a6c080";
static char tagsselbordercolor[]         = "#e67e80";
static char tagsselfloatcolor[]          = "#e67e80";

static char hidnormfgcolor[]             = "#d3c6aa";
static char hidselfgcolor[]              = "#2f383e";
static char hidnormbgcolor[]             = "#a6c080";
static char hidselbgcolor[]              = "#a6c080";

static char urgfgcolor[]                 = "#d3c6aa";
static char urgbgcolor[]                 = "#2f383e";
static char urgbordercolor[]             = "#d699b6";
static char urgfloatcolor[]              = "#d699b6";




static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};





/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "???" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */
static char *tagicons[][NUMTAGS] =
{
 // [DEFAULT_TAGS] = {"???", "???", "???", "???", "???", "???", "???"},
  [DEFAULT_TAGS]        = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
  [ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
  [ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};


/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
	RULE(.class = "Gimp", .tags = 1 << 4)
	RULE(.class = "Firefox", .tags = 1 << 7)
    RULE(.class = "Alacritty", .isterminal = 0)
};



/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
	/* monitor   bar    alignment         widthfunc                 drawfunc                clickfunc                hoverfunc                name */
	{ -1,        0,     BAR_ALIGN_LEFT,   width_tags,               draw_tags,              click_tags,              hover_tags,              "tags" },
	{ -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,           draw_ltsymbol,          click_ltsymbol,          NULL,                    "layout" },
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_status2d,           draw_status2d,          click_statuscmd,         NULL,                    "status2d" },
	{ -1,        0,     BAR_ALIGN_CENTER, width_wintitle,           draw_wintitle,          click_wintitle,          NULL,                    "wintitle" },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static const int decorhints  = 1;    /* 1 means respect decoration hints */



static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "TTT",      bstack },
	{ "|M|",      centeredmaster },
	{ "[D]",      deck },
	{ "[\\]",     dwindle },
};


/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

#define STACKKEYS(MOD,ACTION) \
	{ MOD, XK_j,     ACTION##stack, {.i = INC(+1) } }, \
	{ MOD, XK_k,     ACTION##stack, {.i = INC(-1) } }, \
	{ MOD, XK_m,     ACTION##stack, {.i = 0 } }, 
/*	{ MOD, XK_s,     ACTION##stack, {.i = PREVSEL } }, \
	{ MOD, XK_e,     ACTION##stack, {.i = 1 } }, \
	{ MOD, XK_a,     ACTION##stack, {.i = 2 } }, \
	{ MOD, XK_z,     ACTION##stack, {.i = -1 } },
*/


/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
	"dmenu_run",
	"-m", dmenumon,
	"-fn", dmenufont,
	"-nb", normbgcolor,
	"-nf", normfgcolor,
	"-sb", selbordercolor,
	"-sf", selbgcolor,
	NULL
};
static const char *termcmd[]  = { "alacritty", NULL };

/* This defines the name of the executable that handles the bar (used for signalling purposes) */
#define STATUSBAR "dwmblocks"


static const Key keys[] = {
	/* modifier                     key            function                argument */
	STACKKEYS(MODKEY,                              focus)
	STACKKEYS(MODKEY|ShiftMask,                    push)
//  **************************************** WINDOW *********************************************
	/* modifier                     key            function                argument */
	{ MODKEY,                       XK_q,          killclient,             {0} },
	{ MODKEY,                       XK_u,          setmfact,               {.f = -0.05} },
	{ MODKEY,                       XK_o,          setmfact,               {.f = +0.05} },
	{ MODKEY,                       XK_g,          togglegaps,             {0} },
	{ MODKEY,                       XK_b,          togglebar,              {0} },
	//{ MODKEY|ShiftMask,             XK_space,      togglefloating,         {0} },
	{ MODKEY,                       XK_s,          togglesticky,           {0} },
    { MODKEY,                       XK_space,      zoom,                   {0} },
//  **************************************** SPAWN  *********************************************
	/* modifier                     key            function                argument */
	{ MODKEY,                       XK_Return,     spawn,                  {.v = (const char*[]){ myTerm, NULL} } },	
    { MODKEY,                       XK_d,          spawn,                  {.v = dmenucmd } },
    { MODKEY,                       XK_z,          spawn,                  SHCMD("flameshot gui") },
    { MODKEY,                       XK_w,          spawn,                  {.v = (const char*[]){ myBrowser, NULL} } },
    { MODKEY,                       XK_equal,      spawn,                  SHCMD("~/bin/volup.sh") },
    { MODKEY,                       XK_minus,      spawn,                  SHCMD("~/bin/voldown.sh") },
    { MODKEY,                       XK_0,          spawn,                  SHCMD("~/bin/voltoggle.sh") },
//  **************************************** SYSTEM  *********************************************
	/* modifier                     key            function                argument */
	{ MODKEY|ShiftMask,             XK_q,          quit,                   {0} },
	{ MODKEY|ControlMask,           XK_r,          quit,                   {1} },
	//{ MODKEY,                       XK_space,      setkeymode,             {.ui = COMMANDMODE} },
//  **************************************** LAYOUT  *********************************************
	/* modifier                     key            function                argument */
	{ MODKEY,                       XK_t,          setlayout,              {.v = &layouts[0]} },
//	{ MODKEY,                       XK_i,          mirrorlayout,           {0} },          /* flextile, flip master and stack areas */
	{ MODKEY,                       XK_v,          setlayout,              {.v = &layouts[5]} },
	{ MODKEY,                       XK_c,          setlayout,              {.v = &layouts[4]} },
	{ MODKEY,                       XK_f,          setlayout,              {.v = &layouts[2]} },
//  **************************************** TAGS  *********************************************
	/* modifier                     key            function                argument */
	{ MODKEY,                       XK_l,          shiftview,              { .i = +1 } },
    { Mod1Mask,                     XK_l,          shifttag,               { .i = +1 } },
    { MODKEY|Mod1Mask,              XK_l,          shiftboth,              { .i = +1 } },
	{ MODKEY,                       XK_h,          shiftview,              { .i = -1 } },
    { Mod1Mask,                     XK_h,          shifttag,               { .i = -1 } },
    { MODKEY|Mod1Mask,              XK_h,          shiftboth,              { .i = -1 } },
	{ MODKEY,                       XK_comma,      focusmon,               { .i = -1 } },
	{ MODKEY,                       XK_period,     focusmon,               { .i = +1 } },
    { MODKEY,                       XK_comma,      tagmon,                 { .i = -1 } },
    { MODKEY,                       XK_period,     tagmon,                 { .i = +1 } }, 
   	TAGKEYS(                        XK_1,                                  0)
	TAGKEYS(                        XK_2,                                  1)
	TAGKEYS(                        XK_3,                                  2)
	TAGKEYS(                        XK_4,                                  3)
	TAGKEYS(                        XK_5,                                  4)
	TAGKEYS(                        XK_6,                                  5)
	TAGKEYS(                        XK_7,                                  6)
	TAGKEYS(                        XK_8,                                  7)
	TAGKEYS(                        XK_9,                                  8)
//  **************************************** UNUSED  *********************************************
	/* modifier                     key            function                argument */
    /*
	{ MODKEY,                       XK_Escape,     setkeymode,             {.ui = COMMANDMODE} },
	{ MODKEY,                       XK_p,          spawn,                  {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return,     spawn,                  {.v = termcmd } },
	{ MODKEY,                       XK_b,          togglebar,              {0} },
    STACKKEYS(MODKEY|ShiftMask,                    push)
	{ MODKEY,                       XK_i,          incnmaster,             {.i = +1 } },
	{ MODKEY,                       XK_d,          incnmaster,             {.i = -1 } },
	{ MODKEY,                       XK_h,          setmfact,               {.f = -0.05} },
	{ MODKEY,                       XK_l,          setmfact,               {.f = +0.05} },
	{ MODKEY,                       XK_Return,     zoom,                   {0} },
	{ MODKEY|Mod4Mask,              XK_u,          incrgaps,               {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_u,          incrgaps,               {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_i,          incrigaps,              {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_i,          incrigaps,              {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_o,          incrogaps,              {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_o,          incrogaps,              {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_6,          incrihgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_6,          incrihgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_7,          incrivgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_7,          incrivgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_8,          incrohgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_8,          incrohgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_9,          incrovgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_9,          incrovgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_0,          togglegaps,             {0} },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_0,          defaultgaps,            {0} },
	{ MODKEY,                       XK_Tab,        view,                   {0} },
	{ MODKEY|ShiftMask,             XK_Left,       shifttag,               { .i = -1 } }, // note keybinding conflict with focusadjacenttag tagtoleft
	{ MODKEY|ShiftMask,             XK_Right,      shifttag,               { .i = +1 } }, // note keybinding conflict with focusadjacenttag tagtoright
	{ MODKEY|ShiftMask,             XK_Tab,        shiftview,              { .i = -1 } },
	{ MODKEY|ShiftMask,             XK_backslash,  shiftview,              { .i = +1 } },
	{ MODKEY|ControlMask,           XK_Left,       shiftboth,              { .i = -1 } }, // note keybinding conflict with focusadjacenttag tagandviewtoleft
	{ MODKEY|ControlMask,           XK_Right,      shiftboth,              { .i = +1 } }, // note keybinding conflict with focusadjacenttag tagandviewtoright
	{ MODKEY|ShiftMask,             XK_c,          killclient,             {0} },
	{ MODKEY|ShiftMask,             XK_q,          quit,                   {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,          quit,                   {1} },
	{ MODKEY|ShiftMask,             XK_F5,         xrdb,                   {.v = NULL } },
	{ MODKEY,                       XK_t,          setlayout,              {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,          setlayout,              {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,          setlayout,              {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,      setlayout,              {0} },
	{ MODKEY|ShiftMask,             XK_space,      togglefloating,         {0} },
	{ MODKEY|ShiftMask,             XK_s,          togglesticky,           {0} },
	{ MODKEY,                       XK_0,          view,                   {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,          tag,                    {.ui = ~0 } },
	{ MODKEY,                       XK_comma,      focusmon,               {.i = -1 } },
	{ MODKEY,                       XK_period,     focusmon,               {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,      tagmon,                 {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,     tagmon,                 {.i = +1 } },
	TAGKEYS(                        XK_1,                                  0)
	TAGKEYS(                        XK_2,                                  1)
	TAGKEYS(                        XK_3,                                  2)
	TAGKEYS(                        XK_4,                                  3)
	TAGKEYS(                        XK_5,                                  4)
	TAGKEYS(                        XK_6,                                  5)
	TAGKEYS(                        XK_7,                                  6)
	TAGKEYS(                        XK_8,                                  7)
	TAGKEYS(                        XK_9,                                  8)
    */
};

/******************************************************************************************************/
/*                              KEYMODE PATCH
/******************************************************************************************************/
static const Key cmdkeys[] = {
// 	/* modifier                    keys                     function         argument */
 	{ 0,                           XK_Escape,               clearcmd,        {0} },
// 	{ ControlMask,                 XK_c,                    clearcmd,        {0} },
// 	{ 0,                           XK_Escape,                    setkeymode,      {.ui = INSERTMODE} },
};
// 
static const Command commands[] = {
// 	/* modifier (4 keys)     keysyms (4 keys)       function       argument */
 	{ {0,       0, 0, 0},    {XK_h,     0, 0, 0},   shifttag,      { .i = -1 } },
// 	{ {0,       0, 0, 0},    {XK_h,     0, 0, 0},   spawn,         SHCMD("xdotool key Escape") },
// 	{ {0,       0, 0, 0},    {XK_l,     0, 0, 0},   shifttag,      { .i = +1 } },
// 	{ {0,       0, 0, 0},    {XK_l,     0, 0, 0},   spawn,         SHCMD("xdotool key Escape") },
// 	{ {MODKEY,  0, 0, 0},    {XK_h,     0, 0, 0},   shiftboth,     { .i = -1 } },
// 	{ {MODKEY,  0, 0, 0},    {XK_h,     0, 0, 0},   spawn,         SHCMD("xdotool key Escape") },
// 	{ {MODKEY,  0, 0, 0},    {XK_l,     0, 0, 0},   shiftboth,     { .i = +1 } },
// 	{ {MODKEY,  0, 0, 0},    {XK_l,     0, 0, 0},   spawn,         SHCMD("xdotool key Escape") },
//     { {0,       0, 0, 0},    {XK_comma, 0, 0, 0},   tagmon,        { .i = -1 } },
//     { {0,       0, 0, 0},    {XK_comma, 0, 0, 0},   spawn,         SHCMD("xdotool key Escape") },
// 	{ {0,       0, 0, 0},    {XK_period,0, 0, 0},   tagmon,        { .i = +1 } },
// 	{ {0,       0, 0, 0},    {XK_period,0, 0, 0},   spawn,         SHCMD("xdotool key Escape") },
//     { {0,       0, 0, 0},    {XK_space, 0, 0, 0},   zoom,          { .i = -1 } },
//     { {0,       0, 0, 0},    {XK_space, 0, 0, 0},   spawn,         SHCMD("xdotool key Escape") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                   Button1,        sigstatusbar,   {.i = 1 } },
	{ ClkStatusText,        0,                   Button2,        sigstatusbar,   {.i = 2 } },
	{ ClkStatusText,        0,                   Button3,        sigstatusbar,   {.i = 3 } },
	{ ClkClientWin,         MODKEY,              Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};


