import matplotlib

rgb_colors = {}
for name, hex in matplotlib.colors.cnames.items():
    rgb_colors[name] = matplotlib.colors.to_rgb(hex)

print(rgb_colors)