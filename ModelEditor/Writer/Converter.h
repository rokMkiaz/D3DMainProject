#pragma once
class Converter
{
public:
	Converter();
	~Converter();

	void ReadFile(wstring file);
public:
	void ExportMesh(wstring savePath);

private: 
	void ReadBoneData(aiNode* node, int index, int parent);
	void ReadMeshData(aiNode* node, int bone);  //Bone에 Mesh를 입히는 작업
	void ReadSkinData(); //Skinning을 위한 정점데이터 정보
	void WriteMeshData(wstring savePath); //bone,mesh정보를 파일로 출력


/// ////////////////////////////////////////////////////////////////////////////

public:
	void ExportMaterial(wstring savePath , bool bOverwrite = true );

private:
	void ReadMaterialData();
	void WriteMaterialData(wstring savePath);
	string WriteTexture(string saveFolder, string file);


/// ///////////////////////////////////////////////////////////////////////////

public: //애니메이션
	void ClipList(vector<wstring>* list);
	void ExportAnimClip(UINT index, wstring savePath);
private:
	struct asClip* ReadClipData( aiAnimation* animation);
	void ReadKeyframeData(struct asClip* clip, aiNode* node, vector<struct asClipNode>& aiNodeInfos);
	void WriteClipData(struct asClip* clip, wstring savePath);


private:
	wstring file;

	Assimp::Importer* importer;
	const aiScene* scene; //3D관련 모든내용

	vector<struct asBone* > bones;
	vector<struct asMesh* > meshes;
	vector<struct asMaterial*> materials;
};