// MIT Licensed (see LICENSE.md).
#pragma once

namespace Plasma
{

class TilePaletteSource : public Resource
{
public:
  LightningDeclareType(TilePaletteSource, TypeCopyMode::ReferenceType);

  TilePaletteSource();
  ~TilePaletteSource();

  // Save to a data file
  void Save(StringParam filename) override;
  void Unload() override;
  IntVec2 GetTileDimensions();

  uint mVersion;
  TileMap::TileHashMap mData;
  typedef TileMap::TileHashMap::value_type value_type;
};

class TilePaletteSourceManager : public ResourceManager
{
public:
  DeclareResourceManager(TilePaletteSourceManager, TilePaletteSource);

  TilePaletteSourceManager(BoundType* resourceType);
};

} // namespace Plasma
